#include"Hash_dop.h"
#include<iostream>
using namespace std;

int HashFunction(char l) {
	return (int)tolower(l) - 97;
}

HashTable::HashTable() {
	for (int i = 0; i < SIZE; i++) {
		table[i] = NULL;
	}
}

void HashTable::push(std::string word) {
	int key = HashFunction(word[0]);
	Words* newW = new Words(word);

	if (table[key] == NULL) table[key] = newW;
	else {
		Words* place = table[key];
		while (place->next) place = place->next;
		place->next = newW;
	}
}

void HashTable::print() {
	for (int i = 0; i < SIZE; i++) {
		cout << i << ": ";
		if (table[i] == NULL) cout << "пусто;" << endl;
		else {
			Words* temp = table[i];
			while (temp) {
				cout << temp->word << " --> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
}

void HashTable::search(std::string word) {
	int i = HashFunction(word[0]);

	Words* temp = table[i];
	bool contain = false;
	while (temp) {
		if (temp->word == word) {
			contain = true;
			break;
		}
		temp = temp->next;
	}

	if (contain) {
		cout << i << ": ";
		if (table[i] == NULL) cout << "пусто;" << endl;
		else {
			Words* temp = table[i];
			while (temp) {
				cout << temp->word << " --> ";
				temp = temp->next;
			}
			cout << "NULL" << endl;
		}
	}
	else cout << "Такого слова нет!" << endl;
}