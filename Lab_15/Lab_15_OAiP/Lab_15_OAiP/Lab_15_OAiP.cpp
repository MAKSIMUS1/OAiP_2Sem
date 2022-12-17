#include <iostream>
#include <list>
#include <string>
#include "Hash.h"
using namespace std;

//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[20];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		cin.ignore(cin.rdbuf()->in_avail());
		proverka_2 = 0;
		gets_s(ch);//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("Неверный ввод!\nВведите ещё раз: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}

int main() {
	HashTable HSTable;
	setlocale(LC_ALL, "Rus");
	int choice, key;

	string text;


	for (;;)
	{
		cout << "_________Меню__________________\n";
		cout << "|1 - Вывод хеш-таблицы" << endl;
		cout << "|2 - Добавление элемента" << endl;
		cout << "|3 - Удаление элемента" << endl;
		cout << "|4 - Поиск элемента" << endl;
		cout << "|0 - Выход" << endl;
		cout << "_______________________________\n";
		cout << "Ваш выбор --> " << endl;   
		choice = Correct_Input_Integer();
		switch (choice)
		{
		case 0:
			exit(0);
		case 1:
			HSTable.showTable();
			break;
		case 2:
			cout << "Введите ключ (номер телефона): ";
			key = Correct_Input_Integer();
			if (key > 32767)
			{
				cout << "Введено неправильное число!!!";
				return 0;
			}
			else {
				cout << "Введите информацию (владелец): ";
				cin >> text;
			}
			HSTable.insertItem(key, text);
			break;
		case 3:
			cout << "Введите ключ для удаления: ";
			key = Correct_Input_Integer();
			cout << "Введите информацию (владелец): ";
			cin >> text;
			HSTable.removeItem(key, text);
			break;
		case 4:
			cout << "Введите ключ для поиска: ";
			key = Correct_Input_Integer();
			cout << "Введите информацию (владелец): ";
			cin >> text;
			HSTable.searchTable(key, text);
			break;
		}
	}

}