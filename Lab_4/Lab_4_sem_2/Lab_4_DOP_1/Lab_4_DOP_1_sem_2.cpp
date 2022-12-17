//Определить структуру для представления информации о наличии санаторных путевок, содержащую следующие поля : 
//Название санатория, Место расположения, Лечебный профиль, Количество путевок.
//Представить введенные данные в виде таблицы, данные отсортировать по названиям санаториев.
//Организовать поиск информации и вывод результатов
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>

using namespace std;

struct Sanatorium
{
    char Name[30];
    char location[30];
    char type_of_heal[30];
    int numb_of_vouchers;
};

int name_comp(const void*, const void*);//Для сортировки по алфавиту
int enterValue(Sanatorium*);
void printTable(Sanatorium*);
int Correct_Input_Integer();
const int MAX = 100;
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Sanatorium* list_of_sanatoriums = (Sanatorium*)malloc(MAX * sizeof(struct Sanatorium));
    int i = 0, counter = 0;
    printf("Заполнение информации о снаториях.\n");
    printf("Для завершения ввода введите в поле 'Название': ***\n");
    while (i < MAX)
    {
        printf("------------------------------------------------------\n");
        printf("Санаторий номер %d.\nНазвание санатория: ", i + 1);
        if (enterValue(&list_of_sanatoriums[i]) != 1)
            break;
        i++;
        counter++;
    }
    if (counter == 0)
        printf("Завершение работы программы.\n");
    else
    {
        qsort(list_of_sanatoriums, counter, sizeof(list_of_sanatoriums[0]), name_comp);
        printf("|---------------------------------------------------------------------------------------|\n");
        printf("|                                           Санатории                                   |\n");
        printf("|---------------------------------------------------------------------------------------|\n");
        printf("|Название                 |Место                    |Лечебный профиль|Количество путевок|\n");
        printf("|---------------------------------------------------------------------------------------|\n");
        i = 0;
        while (i < counter)
        {
                printTable(&list_of_sanatoriums[i]);
                i++;
        }
        printf("|Пометка: С - Сердечно-сосудистый, Д - Дыхательный, O - опорно-двигательный             |\n");
        printf("|---------------------------------------------------------------------------------------|\n");
    }
    return 0;
}

//FUNCTIONS
int enterValue(Sanatorium* p)
{
    bool pr = false;
    do {
        pr = false;
        cin.ignore(cin.rdbuf()->in_avail());
        gets_s(p->Name);
        for (int k = 0; k < strlen(p->Name); k++)
            if ((p->Name[k] < 'A' || p->Name[k] > 'Z') && (p->Name[k] < 'a' || p->Name[k] > 'z') && (p->Name[k] < 'А' || p->Name[k] > 'я') && (p->Name[k] != ' '))
                pr = true;
        if (p->Name[0] == '\0')
            pr = true;
        if (p->Name[0] == '*' && p->Name[1] == '*' && p->Name[2] == '*' && p->Name[3] == '\0')
            pr = false;
        if (pr == true)
            printf("Неккоретный ввод, можно вводить только буквы!(или ***).\nВведите ещё раз: ");
    } while (pr == true);
    if (!strcmp(p->Name, "***"))
        return 2;
    printf("Место санатория: ");
    do {
        pr = false;
        cin.ignore(cin.rdbuf()->in_avail());
        gets_s(p->location);
        for (int k = 0; k < strlen(p->location); k++)
            if ((p->location[k] < 'A' || p->location[k] > 'Z') && (p->location[k] < 'a' || p->location[k] > 'z') && (p->location[k] < 'А' || p->location[k] > 'я') && (p->Name[k] != ' '))
                pr = true;
        if (p->location[0] == '\0')
            pr = true;
        if (pr == true)
            printf("Неккоретный ввод, можно вводить только буквы!.\nВведите ещё раз: ");
    } while (pr == true);
    printf("Лечебный профиль(С - Сердечно-сосудистый, Д - Дыхательный, O - опорно-двигательный): ");
    do {
        pr = true;
        cin.ignore(cin.rdbuf()->in_avail());
        gets_s(p->type_of_heal);
        if (p->type_of_heal[0] == 'С' && p->type_of_heal[1] == '\0')
            pr = false;
        if (p->type_of_heal[0] == 'Д' && p->type_of_heal[1] == '\0')
            pr = false;
        if (p->type_of_heal[0] == 'О' && p->type_of_heal[1] == '\0')
            pr = false;
        if (pr == true)
            printf("Неккоретный ввод, можно вводить только 'С' или 'Д' или 'О'.\nВведите ещё раз: ");
    } while (pr == true);
    printf("Количество путевок: ");
    p->numb_of_vouchers = Correct_Input_Integer();
    return 1;
}

void printTable(Sanatorium* p)
{
    printf("|%-25s|%-25s|%-16s|%-18d|\n", p->Name, p->location, p->type_of_heal, p->numb_of_vouchers);
    printf("|---------------------------------------------------------------------------------------|\n");
}

//Сравнение названий
int name_comp(const void* a, const void* b)
{
    return _stricmp(((Sanatorium*)a)->Name, ((Sanatorium*)b)->Name);//_stricmp() не делает различия между буквами верхнего и нижнего регист­ров. Поэтому не strcmp()
}

//Функции проверок
 
//Корректный ввод integer
int Correct_Input_Integer() {
    int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
    char ch[11];

    while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
    { //Если proverka_2 = 1, значит ввод неверный.
        cin.ignore(cin.rdbuf()->in_avail());
        gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
        if (ch[0] == '-')
            proverka_na_minus = 1;
        else
            if (ch[0] >= '0' && ch[0] <= '9')
                proverka_na_minus = 2;
            else
                proverka_2 = 1;
        if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
            for (int i = 1; i < strlen(ch); i++) {
                if (ch[i] <= '0' || ch[i] >= '9') {
                    proverka_2 = 1;
                }
                if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
                    proverka_2 = 0;
                }
            }
        if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
            for (int i = 0; i < strlen(ch); i++) {
                if (ch[i] <= '0' || ch[i] >= '9') {
                    proverka_2 = 1;
                }
                if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
                    proverka_2 = 0;
                }
                if (ch[i] == '\n')
                    break;
            }
        cin.clear();
        proverka_na_minus = 0;
        if (proverka_2 == 1 || atoi(ch) < 0)
            printf("Неверный ввод!\nВведите ещё раз: ");
        if (proverka_2 == 0 && atoi(ch) >= 0)
            proverka = 1;
    }
    value = atoi(ch);
    return value;
}