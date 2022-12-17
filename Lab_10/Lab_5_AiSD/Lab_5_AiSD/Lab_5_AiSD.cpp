//Задание на выполнение
//1.	В разработанное приложение(на стеках) необходимо ввести символьную строку, которая может содержать цифры, буквы, знаки математических операций(+, -, *, / ) и три вида скобок : (), [] и{}.
//Определить, верно ли расставлены скобки(символы между скобками не учитывать).Например, в строках()[{}] и[{}([])] скобки расставлены верно, а в строках([)] и ]]](((-неверно.
//В качестве ответа вывести текст «скобки расставлены верно» или «скобки расставлены не верно».
#include <iostream>

using namespace std;

int main() {
    int pos = -1;
    setlocale(LC_ALL, "ru");
    char s[30];
    cin >> s;
    int kol_skob = 0;
	for(int i = 0; i < strlen(s); i++)
        if (s[i] == '(') kol_skob++;
        else
            if (s[i] == ')') kol_skob++;
            else
                if (s[i] == '{') kol_skob++;
                else
                    if (s[i] == '}') kol_skob++;
                    else
                        if (s[i] == '[') kol_skob++;
                        else
                            if (s[i] == ']') kol_skob++;
    int kol_skob_end = 0, kol_skob_start = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(') kol_skob_start++;
        else
            if (s[i] == ')') kol_skob_end++;
            else
                if (s[i] == '{') kol_skob_start++;
                else
                    if (s[i] == '}') kol_skob_end++;
                    else
                        if (s[i] == '[') kol_skob_start++;
                        else
                            if (s[i] == ']') kol_skob_end++;
    if (kol_skob % 2 != 0 || kol_skob_end != kol_skob_start)
        printf("Скобки расставлены не верно.\n");
    else {
        char* skobki = new char[kol_skob];
        for (int i = 0; i < kol_skob; i++)
            if (s[i] == '(') skobki[i] = s[i];
            else
                if (s[i] == ')') skobki[i] = s[i];
                else
                    if (s[i] == '{') skobki[i] = s[i];
                    else
                        if (s[i] == '}') skobki[i] = s[i];
                        else
                            if (s[i] == '[') skobki[i] = s[i];
                            else
                                if (s[i] == ']') skobki[i] = s[i];
        char last_skobka = 'f';
        char stack[100];
        bool prov = true;
        for (int i = 0; i < kol_skob; i++) {
            if ((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
                last_skobka = s[i];
                pos++;
                stack[pos] = s[i];
            }
            if ((pos == -1) && (s[i] == ')' || s[i] == '}' || s[i] == ']')) {
                prov = false;
                break;
            }

            if (((s[i] == ')') && (last_skobka != '(')) ||
                ((s[i] == '}') && (last_skobka != '{')) ||
                ((s[i] == ']') && (last_skobka != '[')))
            {
                prov = false;
                break;
            }
            if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
            {
                pos--;
                if (pos >= 0)
                    last_skobka = stack[pos];
            }
        }
        if(prov == false)
            printf("Скобки расставлены не верно.\n");
        else
            printf("Скобки расставлены верно.\n");
        delete[] skobki;
    }
}
