////Определить структуру для представления информации о сданных студентом экзаменах, содержащую поля : 
////ФИО студента, число экзаменов, полученные оценки.
////Определить функции для обработки отдельного объекта(например, для проверки, сданы ли все экзамены на 4 и 5).
////Написать функцию для обработки массива структур.
////В результате обработки требуется вычислить характеристику успеваемости студентов, то есть отношение числа студентов, сдавших экзамены на 4 и 5, к общему числу студентов, в процентах.
#include <iostream>               
#include <stdio.h>  
#include <windows.h>
# define _CRT_SECURE_NO_WARNINGS
# define str_len 30               

using namespace std;

//struct Student
//{
//    char name_familiya[str_len];
//    char name[str_len];
//    char name_otchestvo[str_len];
//    int numb_of_exams;
//    int ozenki[50];
//};
//
//int name_comp(const void*, const void*);//Для сортировки по алфавиту
//int enterValue(Student*);
//int uspevaemost(Student*);
//bool proverka_uspevaemosti(Student*);
//int Correct_Input_Integer();
//int Correct_Input_Integer_Ozenki();
//const int MAX = 100;
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    Student* spisok_students = (Student*)malloc(MAX * sizeof(struct Student));
//    int i = 0, counter = 0, good = 0;
//    float sredn = 1;
//    printf("Заполнение информации о студентах.\n");
//    printf("Для завершения ввода введите в поле 'Фамилия': ***\n");
//    while (i < MAX)
//    {
//        printf("------------------------------------------------------\n");
//        printf("Студент номер % d.\n", i + 1);
//        if (enterValue(&spisok_students[i]) != 1)
//            break;
//        i++;
//        counter++;
//    }
//    if (counter == 0)
//        printf("Завершение работы программы.\n");
//    else
//    {
//        for (int i = 0; i < counter; i++) 
//            if (uspevaemost(&spisok_students[i]) == 1)
//                good++;
//        sredn = (float)good / (float)counter;
//        printf("Студенты сдавшие экзамены на 4 и 5: %0.0f%%\n", sredn * 100);
//        printf("Желаете ли проверить на успеваемость?(1 - Да, 2 - Нет)\n");
//        int vibor, vibor_studenta;
//        bool prrr = true;
//        do {
//            vibor = Correct_Input_Integer();
//            if (vibor == 1 || vibor == 2)
//                prrr = false;
//            else
//                printf("Неправильный выбор! Повторите попытку: ");
//        } while (prrr == true);
//        if (vibor == 1) {
//            printf("Какого студента по номеру вы желаете проверить?\n");
//            prrr = true;
//            do {
//                vibor_studenta = Correct_Input_Integer();
//                if (vibor_studenta > 0 && vibor_studenta <= counter)
//                    prrr = false;
//                else
//                    printf("Неправильный выбор! Повторите попытку: ");
//            } while (prrr == true);
//            if (proverka_uspevaemosti(&spisok_students[vibor_studenta - 1]) == true)
//                printf("Студент номер %d успешно всё сдал.\n", vibor_studenta);
//            if (proverka_uspevaemosti(&spisok_students[vibor_studenta - 1]) == false)
//                printf("Студент номер %d не успешно всё сдал.\n", vibor_studenta);
//        }
//    }
//    return 0;
//}
//
////FUNCTIONS
//bool proverka_uspevaemosti(Student* p) {
//    int proff = 0;
//    for (int g = 0; g < p->numb_of_exams; g++)
//        if (p->ozenki[g] == 4 || p->ozenki[g] == 5)
//            proff++;
//    if (proff == p->numb_of_exams)
//        return true;
//    else
//        return false;
//}
//int uspevaemost(Student* p) {
//    int proff = 0;
//    for (int g = 0; g < p->numb_of_exams; g++)
//        if (p->ozenki[g] == 4 || p->ozenki[g] == 5)
//            proff++;
//    if (proff == p->numb_of_exams)
//        return 1;
//}
//int enterValue(Student* p)
//{
//    bool pr = false;
//    printf("Фамилия: ");
//    do {
//        pr = false;
//        cin.ignore(cin.rdbuf()->in_avail());
//        gets_s(p->name_familiya);
//        for (int k = 0; k < strlen(p->name_familiya); k++)
//            if ((p->name_familiya[k] < 'A' || p->name_familiya[k] > 'Z') &&
//                (p->name_familiya[k] < 'a' || p->name_familiya[k] > 'z') &&
//                (p->name_familiya[k] < 'А' || p->name_familiya[k] > 'я') &&
//                (p->name_familiya[k] != ' '))
//                pr = true;
//        if (p->name_familiya[0] == '\0')
//            pr = true;
//        if (p->name_familiya[0] == '*' && p->name_familiya[1] == '*' && p->name_familiya[2] == '*' && p->name_familiya[3] == '\0')
//            pr = false;
//        if (pr == true)
//            printf("Неккоретный ввод, можно вводить только буквы!(или ***).\nВведите ещё раз: ");
//    } while (pr == true);
//    if (!strcmp(p->name_familiya, "***"))
//        return 2;
//    printf("Имя: ");
//    do {
//        pr = false;
//        cin.ignore(cin.rdbuf()->in_avail());
//        gets_s(p->name);
//        for (int k = 0; k < strlen(p->name); k++)
//            if ((p->name[k] < 'A' || p->name[k] > 'Z') &&
//                (p->name[k] < 'a' || p->name[k] > 'z') &&
//                (p->name[k] < 'А' || p->name[k] > 'я') &&
//                (p->name[k] != ' '))
//                pr = true;
//        if (p->name[0] == '\0')
//            pr = true;
//        if (pr == true)
//            printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
//    } while (pr == true);
//    printf("Отчество: ");
//    do {
//        pr = false;
//        cin.ignore(cin.rdbuf()->in_avail());
//        gets_s(p->name_otchestvo);
//        for (int k = 0; k < strlen(p->name_otchestvo); k++)
//            if ((p->name_otchestvo[k] < 'A' || p->name_otchestvo[k] > 'Z') &&
//                (p->name_otchestvo[k] < 'a' || p->name_otchestvo[k] > 'z') &&
//                (p->name_otchestvo[k] < 'А' || p->name_otchestvo[k] > 'я') &&
//                (p->name_otchestvo[k] != ' '))
//                pr = true;
//        if (p->name_otchestvo[0] == '\0')
//            pr = true;
//        if (pr == true)
//            printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
//    } while (pr == true);
//    printf("Введите количество экзаменов: ");
//    p->numb_of_exams = Correct_Input_Integer();
//    for (int k = 0; k < p->numb_of_exams; k++) {
//        printf("Оценка №%d: ", k + 1);
//        p->ozenki[k] = Correct_Input_Integer_Ozenki();
//    }
//    return 1;
//}
//
////Функции проверок
//int Correct_Input_Integer() {
//    int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
//    char ch[11];
//
//    while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
//    { //Если proverka_2 = 1, значит ввод неверный.
//        cin.ignore(cin.rdbuf()->in_avail());
//        gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
//        if (ch[0] == '-')
//            proverka_na_minus = 1;
//        else
//            if (ch[0] >= '0' && ch[0] <= '9')
//                proverka_na_minus = 2;
//            else
//                proverka_2 = 1;
//        if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
//            for (int i = 1; i < strlen(ch); i++) {
//                if (ch[i] <= '0' || ch[i] >= '9') {
//                    proverka_2 = 1;
//                }
//                if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
//                    proverka_2 = 0;
//                }
//            }
//        if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
//            for (int i = 0; i < strlen(ch); i++) {
//                if (ch[i] <= '0' || ch[i] >= '9') {
//                    proverka_2 = 1;
//                }
//                if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
//                    proverka_2 = 0;
//                }
//                if (ch[i] == '\n')
//                    break;
//            }
//        cin.clear();
//        proverka_na_minus = 0;
//        if (proverka_2 == 1 || atoi(ch) < 0)
//            printf("Неверный ввод!\nВведите ещё раз: ");
//        if (proverka_2 == 0 && atoi(ch) >= 0)
//            proverka = 1;
//    }
//    value = atoi(ch);
//    return value;
//}
//int Correct_Input_Integer_Ozenki() {
//    int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
//    char ch[11];
//
//    while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
//    { //Если proverka_2 = 1, значит ввод неверный.
//        cin.ignore(cin.rdbuf()->in_avail());
//        gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
//        if (ch[0] == '-')
//            proverka_na_minus = 1;
//        else
//            if (ch[0] >= '0' && ch[0] <= '9')
//                proverka_na_minus = 2;
//            else
//                proverka_2 = 1;
//        if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
//            for (int i = 1; i < strlen(ch); i++) {
//                if (ch[i] <= '0' || ch[i] >= '9') {
//                    proverka_2 = 1;
//                }
//                if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
//                    proverka_2 = 0;
//                }
//            }
//        if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
//            for (int i = 0; i < strlen(ch); i++) {
//                if (ch[i] <= '0' || ch[i] >= '9') {
//                    proverka_2 = 1;
//                }
//                if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
//                    proverka_2 = 0;
//                }
//                if (ch[i] == '\n')
//                    break;
//            }
//        cin.clear();
//        proverka_na_minus = 0;
//        if (proverka_2 == 1 || atoi(ch) < 0 || atoi(ch) > 5)
//            printf("Неверный ввод!\nВведите ещё раз: ");
//        if (proverka_2 == 0 && atoi(ch) >= 0 && atoi(ch) <= 5)
//            proverka = 1;
//    }
//    value = atoi(ch);
//    return value;
//}
void foo(const int inp, int& outx, int& outy, int& outz)
{
    outx = inp + 10;
    outy = inp + 20;
    outz = inp + 30;
}
int main()
{
    int x, y, z;
    foo(10, x, y, z);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    return 0;
}