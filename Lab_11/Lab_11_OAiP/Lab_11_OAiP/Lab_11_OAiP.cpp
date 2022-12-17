#include"Header.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

void menu() {
	setlocale(LC_ALL, "Rus");
	cout << " ______________________________________________________Меню_________________________________________" << endl;
	cout << "/1  - для добавления элемента;									    \\\n";
	cout << "|2  - для удаления элемента;									     |\n";
	cout << "|3  - для вывода дерева;									     |\n";
	cout << "|4  - для очистки дерева;									     |\n";
	cout << "|5  - Количество вершин дерева, являющихся левыми дочерними вершинами (корень дерева не учитывается);|\n";
	cout << "|6  - Количество листьев данного дерева;							     |\n";
	cout << "|0  - для выхода;										     |\n";
	cout << "\\____________________________________________________________________________________________________/" << endl;
	cout << "Ваш выбор: ";
}

int main() {
	setlocale(LC_ALL, "Rus");

	tNode* tree = nullptr;
	int choice;

	menu();
	do {
		choice = Correct_Input_Integer();
		switch (choice) {
		case 1: {
			int x;
			cout << "Введите элемент: ";
			x = Correct_Input_Integer();
			tree = input(tree, x);
			break;
		}
		case 2: {
			int x;
			cout << "Введите элемент: ";
			x = Correct_Input_Integer();
			tree = del(tree, x);
			break;
		}
		case 3: {
			show(tree, 0);
			break;
		}
		case 4: {
			tClear(tree);
			cout << "Дерево очищено" << endl;
			tree = nullptr;
			break;
		}
		case 5: {
			int sum = 0;
			onlyLeft(tree, sum);
			cout << "Количество левых дочерних вершин: " << sum << endl;
			break;
		}
		case 6: {
			int count = 0;
			leaves(tree, count);
			cout << "Количество листьев во всем дереве: " << count << endl;
			break;
		}
		}
		if (choice) cout << "\nЧто дальше? --> ";
	} while (choice);
}