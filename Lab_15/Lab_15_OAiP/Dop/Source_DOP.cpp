#include"Hash_dop.h"
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	ifstream fin("Some_words.txt");
	HashTable H;

	string words[70];
	string temp;
	int sz = 0;
	while (true) {
		fin >> temp;
		if (fin.eof()) break;

		words[sz] = temp;
		sz++;
	}

	for (int i = 0; i < sz; i++) {
		H.push(words[i]);
	}
	cout << "Таблица:" << endl;
	H.print();

	cout << "______________________________________________________________________________________________" << endl;
	string search;
	while (true) {
		cout << "Поиск по слову (0 - для выхода): "; cin >> search;
		if (search == "0") break;
		H.search(search);
	}
}