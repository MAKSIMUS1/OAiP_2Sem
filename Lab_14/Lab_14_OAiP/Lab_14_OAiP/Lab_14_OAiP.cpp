#include "Hash.h"
#include <iostream>
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

struct AAA {
	int key;
	char* word;
	AAA(int k, char* w) {
		key = k;
		word = w;
	}
	AAA() {};
};

int key(void* d) {
	AAA* f = (AAA*)d;
	return f->key;
}

void print(void* d) {
	cout << "Ключ: " << ((AAA*)d)->key << "; Слово: " << ((AAA*)d)->word << ";" << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	int size, choice;
	AAA* a;
	char* word;

	cout << "Введите размер хеш-таблицы: ";
	size = -2;
	while (size <= 0) {
		size = Correct_Input_Integer();
		if (size <= 0)
			cout << "Неверно. Введите ещё раз: ";
	}
	system("cls");		//очистка консоли
	HashTable H = HashTable(size, key);

	do {
		cout << "_________Меню_____________" << endl;
		cout << "1 - добавление элемента;" << endl;
		cout << "2 - вывод хеш-таблицы;" << endl;
		cout << "3 - удаление элемента;" << endl;
		cout << "4 - поиск элемента;" << endl;
		cout << "0 - выход: " << endl;
		cout << "__________________________" << endl;
		cout << "Выбор -> ";

		choice = Correct_Input_Integer();

		switch (choice) {
		case 1:
			int choice_insert;
			cout << "11 - добавление элемента с помощью универсального хеширования;" << endl;
			cout << "12 - добавление элемента с помощью модульного хеширования;" << endl;
			cout << "Ваш выбор: ";
			choice_insert = Correct_Input_Integer();
			switch (choice_insert) {
			case 11:
				if (H.current == H.size) cout << "Таблица заполнена!" << endl;
				else {
					int k, length{};
					a = new AAA;
					cout << "Введите ключ: ";
					k = Correct_Input_Integer();
					a->key = k;
					word = new char[10];
					cout << "Введите слово: ";
					cin >> word;
					for (int i{}; word[i] != '\0'; i++) {
						length++;
					}
					a->word = word;
					H.UniversalInsert(a, length);
					break;
				}
			case 12:
				if (H.current == H.size) cout << "Таблица заполнена!" << endl;
				else {
					int k;
					a = new AAA;
					cout << "Введите ключ: ";
					k = Correct_Input_Integer();
					a->key = k;
					word = new char[10];
					cout << "Введите слово: ";
					cin >> word;
					a->word = word;
					H.ModulInsert(a);
					break;
				}
			}
			break;
		case 2:
			H.Scan(print);
			break;
		case 3:
			int choice_remove;
			cout << "31 - удаление элемента с помощью универсального хеширования;" << endl;
			cout << "32 - удаление элемента с помощью модульного хеширования;" << endl;
			cout << "Ваш выбор: ";
			choice_remove = Correct_Input_Integer();
			switch (choice_remove) {
			case 31: {
				int k, length{};
				cout << "Введите ключ для удаления: ";
				k = Correct_Input_Integer();
				word = new char[10];
				cout << "Введите слово: ";
				cin >> word;
				for (int i{}; word[i] != '\0'; i++) {
					length++;
				}
				H.UniversalDelete(k, length);
				break;
			}
			case 32: {
				int k;
				cout << "Введите ключ для удаления: ";
				k = Correct_Input_Integer();
				H.ModulDelete(k);
				break;
			}
			}
			break;
		case 4:
			int choice_search;
			cout << "41 - поиск элемента с помощью универсального хеширования;" << endl;
			cout << "42 - поиск элемента с помощью модульного хеширования;" << endl;
			cout << "Ваш выбор: ";
			choice_search = Correct_Input_Integer();
			switch (choice_search) {
			case 41:
				if (H.current) {
					int k, length{};
					cout << "Введите ключ: ";
					k = Correct_Input_Integer();
					word = new char[10];
					cout << "Введите слово: ";
					cin >> word;
					for (int i{}; word[i] != '\0'; i++) {
						length++;
					}
					if (H.UniversalSearch(k, length)) print(H.UniversalSearch(k, length));
					else cout << "Ключ не найден!" << endl;
				}
				else cout << "Таблица пуста!" << endl;
				break;
			case 42:
				if (H.current) {
					int k, length{};
					cout << "Введите ключ: ";
					k = Correct_Input_Integer();
					if (H.ModulSearch(k)) print(H.ModulSearch(k));
					else cout << "Ключ не найден!" << endl;
				}
				else cout << "Таблица пуста!" << endl;
				break;
			}
		}
	} while (choice);
}