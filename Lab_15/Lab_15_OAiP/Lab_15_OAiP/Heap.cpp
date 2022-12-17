#include <iostream>
#include <list>
#include <string>
#include "Hash.h"
#define INT_MAX 32767
using namespace std;

const int Mlength = 8;
const double A = (sqrt(5) - 1) / 2; //������� �������

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
	//.first � .second ����� �������������� ���� ��� ��������� (������) ��� pair (������ ��� pair)
	int hashValue = hashFunction(key, text);
	auto& cell = table[hashValue];
	//list<pair<int, string>>& cell = table[hashValue];
	auto x = begin(cell);	//�������� ��������� �� ������ �������
	//auto x = cell.begin();
	bool keyExists = false;
	for (; x != end(cell); x++) {
		if (x->first == key) {
			keyExists = true;
			x->second = text;
			cout << "���� ����������. ���������� ��������" << endl;
			break;
		}
	}
	if (!keyExists) {
		cell.emplace_back(key, text);//push_back ������ ���� �����, �� ������� ��������� ������ ��� ����������� ������� � ������ ����� 
	}
	return;
}

void HashTable::removeItem(int key, string text) {
	//.first � .second ����� �������������� ���� ��� ��������� (������) ��� pair (������ ��� pair)
	int hashValue = hashFunction(key, text);
	auto& cell = table[hashValue];	//�������� ������ c auto
	auto x = begin(cell);	//�������� ��������� �� ������ �������
	bool keyExists = false;
	for (; x != end(cell); x++) {
		if (x->first == key) {
			keyExists = true;
			x = cell.erase(x);
			cout << "���� ������." << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "���� �� ������!" << endl;
	}
	return;
}

void HashTable::showTable() {
	if (isEmpty()) {
		cout << "���-������� �����." << endl;
	}
	else {
		for (int i = 0; i < HashGroups; i++) {
			if (table[i].size() == 0) {
				cout << "����[" << i << "]: �� �����." << endl;
				continue; //����� ���� � ����� ����� ��� ������ continue
			}
			auto x = table[i].begin();
			for (; x != table[i].end(); x++) {
				cout << "����[" << i << "]: " << x->first << "\t �����: " << x->second << endl;
			}
		}
	}
	return;
}

void HashTable::searchTable(int key, string text) {
	int hashValue = hashFunction(key, text);
	auto& cell = table[hashValue];	//�������� ������ c auto
	auto x = begin(cell);	//�������� ��������� �� ������ �������
	bool keyExists = false;
	for (; x != end(cell); x++) {
		if (x->first == key) {
			keyExists = true;
			cout << "���� ������." << endl;
			cout << "����: " << x->first << ";\t �����: " << x->second << endl;
			break;
		}
	}
	if (!keyExists) {
		cout << "���� �� ������!" << endl;
	}
	return;
}