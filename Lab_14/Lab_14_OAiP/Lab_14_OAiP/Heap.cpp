#include "Hash.h"
#include <iostream>
#include <math.h>

using namespace std;
const int Mlength = 8;
const double A = (sqrt(5) - 1) / 2;	 //золотое сечение

// Универсальное хеширование - подразумевает случайный выбор хеширования из списка. При изменении мультипликативного метода, можно получить универсальное хеширование.
// (A - случайное число, но генерация сожрет очень много ресурсов)
// Используем псевдослучайные числа.



int ModulHashFunction(int key, int size) {
	return key % size;
}

int MultiplicativeHashFunction(int key, int size) {
	return size * fmod((key * A), 1);
}

int UniversalHashFunction(int length, int size) {
	int a = Mlength / 3;
	int b = Mlength / 2;
	return ((a * length + b) % Mlength) % size;
}

HashTable::HashTable(int size, int(*getkey)(void*)) {
	current = 0;

	this->size = size;
	this->GetKey = getkey;
	this->Data = new void* [size];
	for (int i = 0; i < size; i++) {
		Data[i] = NULL;
	}
}

void HashTable::UniversalInsert(void* d, int length) {
	for (int t = GetKey(d), j = UniversalHashFunction(length, size);; j++) {
		if (j == size) {
			j = 0;
		}
		if (!Data[j] || Data[j] == DEL) {
			Data[j] = d;
			current++;
			break;
		}
	}
}

void HashTable::ModulInsert(void* d) {
	for (int t = GetKey(d), j = ModulHashFunction(t, size);; j++) {
		if (j == size) {
			j = 0;
		}
		if (!Data[j] || Data[j] == DEL) {
			Data[j] = d;
			current++;
			break;
		}
	}
}

void HashTable::MultiplicativeInsert(void* d) {
	for (int t = GetKey(d), j = MultiplicativeHashFunction(t, size);; j++) {
		if (j == size) {
			j = 0;
		}
		if (!Data[j] || Data[j] == DEL) {
			Data[j] = d;
			current++;
			break;
		}
	}
}

void HashTable::Scan(void(*f)(void*)) {
	for (int i = 0; i < this->size; i++) {
		cout << "Элемент " << i << ": ";
		if (!this->Data[i]) cout << "пусто;" << endl;
		else if (this->Data[i] == DEL) cout << "удален;" << endl;
		else f((this->Data)[i]);
	}
}

int HashTable::UniversalSearchPos(int key, int length) {
	int position = -1;
	for (int i = UniversalHashFunction(length, size), count = 0; count < size && Data[i]; i++, count++) {
		if (i == size) {
			i = -1;
			continue;
		}
		if (Data[i] != DEL) {
			if (GetKey(Data[i]) == key) {
				position = i;
				break;
			}
		}
	}
	return position;
}

void* HashTable::UniversalSearch(int key, int length) {
	int position = UniversalSearchPos(key, length);
	return (position > 0) ? Data[position] : NULL;
}

int HashTable::ModulSearchPos(int key) {
	int position = -1;
	for (int i = ModulHashFunction(key, size), count = 0; count < size && Data[i]; i++, count++) {
		if (i == size) {
			i = -1;
			continue;
		}
		if (Data[i] != DEL) {
			if (GetKey(Data[i]) == key) {
				position = i;
				break;
			}
		}
	}
	return position;
}

void* HashTable::ModulSearch(int key) {
	int position = ModulSearchPos(key);
	return (position > 0) ? Data[position] : NULL;
}

int HashTable::MultiplicativeSearchPos(int key) {
	int position = -1;
	for (int i = MultiplicativeHashFunction(key, size), count = 0; count < size && Data[i]; i++, count++) {
		if (i == size) {
			i = -1;
			continue;
		}
		if (Data[i] != DEL) {
			if (GetKey(Data[i]) == key) {
				position = i;
				break;
			}
		}
	}
	return position;
}

void* HashTable::MultiplicativeSearch(int key) {
	int position = MultiplicativeSearchPos(key);
	return (position > 0) ? Data[position] : NULL;
}

void HashTable::UniversalDelete(int key, int length) {
	int i = UniversalSearchPos(key, length);

	if (i != -1) {
		if (Data[i]) {
			Data[i] = DEL;
			current--;
		}
	}
	else cout << "Ключ не найден!" << endl;
}

void HashTable::ModulDelete(int key) {
	int i = ModulSearchPos(key);

	if (i != -1) {
		if (Data[i]) {
			Data[i] = DEL;
			current--;
		}
	}
	else cout << "Ключ не найден!" << endl;
}

void HashTable::MultiplicativeDelete(int key) {
	int i = MultiplicativeSearchPos(key);

	if (i != -1) {
		if (Data[i]) {
			Data[i] = DEL;
			current--;
		}
	}
	else cout << "Ключ не найден!" << endl;
}
