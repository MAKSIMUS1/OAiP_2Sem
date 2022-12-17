#include <iostream>
#include <list>
#include <string>
#include "Hash.h"
#define INT_MAX 32767
using namespace std;

const int Mlength = 8;
const double A = (sqrt(5) - 1) / 2; //золотое сечение

bool HashTable::isEmpty() const {
	int realsize{}; //int realsize = 0;
	for (int i = 0; i < HashGroups; i++) {
		realsize += table[i].size();
	}
	if (!realsize) {
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key, string text) {
	int length = text.length();
	int a = Mlength / 3;
	int b = Mlength / 2;
	return ((a * length + b) % Mlength) % HashGroups;
	// return key % HashGroups;
}

void HashTable::insertItem(int key, string text) {
	//.first и .second могут использоваться если они объявлены (неявно) как pair (только для pair)
	int hashValue = hashFunction(key, text);
	auto& cell = table[hashValue];
	//list<pair<int, string>>& cell = table[hashValue];
	auto x = begin(cell);	//передает указатель на начало массива
	//auto x = cell.begin();
	bool keyExists = false;
	for (; x != end(cell); x++) {
		if (x->first == key) {
			keyExists = true;
			x->second = text;
			cout << "Ключ существует. Информация заменена" << endl;
			break;
		}
	}
	if (!keyExists) {
		cell.emplace_back(key, text);//push_back делает тоже самое, но создает временный объект для перемещения объекта в другое место 
	}
	return;
}

void HashTable::removeItem(int key, string text) {
	//.first и .second могут использоваться если они объявлены (неявно) как pair (только для pair)
	int hashValue = hashFunction(key, text);
	auto& cell = table[hashValue];	//работает только c auto
	auto x = begin(cell);	//передает указатель на начало массива
	bool keyExists = false;
	for (; x != end(cell); x++) {
		if (x->first == key) {
			keyExists = true;
			x = cell.erase(x);
			cout << "Ключ удален." << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "Ключ не найден!" << endl;
	}
	return;
}

void HashTable::showTable() {
	if (isEmpty()) {
		cout << "Хеш-таблица пуста." << endl;
	}
	else {
		for (int i = 0; i < HashGroups; i++) {
			if (table[i].size() == 0) {
				cout << "Ключ[" << i << "]: не задан." << endl;
				continue; //сразу идем в конец цикла при помощи continue
			}
			auto x = table[i].begin();
			for (; x != table[i].end(); x++) {
				cout << "Ключ[" << i << "]: " << x->first << "\t Текст: " << x->second << endl;
			}
		}
	}
	return;
}

void HashTable::searchTable(int key, string text) {
	int hashValue = hashFunction(key, text);
	auto& cell = table[hashValue];	//работает только c auto
	auto x = begin(cell);	//передает указатель на начало массива
	bool keyExists = false;
	for (; x != end(cell); x++) {
		if (x->first == key) {
			keyExists = true;
			cout << "Ключ найден." << endl;
			cout << "Ключ: " << x->first << ";\t Текст: " << x->second << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "Ключ не найден!" << endl;
	}
	return;
}