#include<iostream>
using namespace std;

struct tNode {
	int data;
	tNode* left, * right;
};

void show(tNode*, int);
tNode* input(tNode*, int);
tNode* del(tNode*, int);
void tClear(tNode*);
void Directbypass(tNode*);
void Symmetricbypass(tNode*);
void Reversebypass(tNode*);
bool isBalanced(tNode*);

int Correct_Input_Integer();


int main() {
	setlocale(LC_ALL, "RUS");
	tNode* tree = nullptr;
	int choice;
	cout << " ____________________Меню____________________" << endl;
	cout << "/1  - для добавления элемента;\n";
	cout << "|2  - для удаления элемента;	\n";
	cout << "|3  - для вывода дерева;\n";
	cout << "|4  - для очистки дерева;\n";
	cout << "|5 - для прямого(нисходящий) обхода;\n";
	cout << "|6 - для симметричного обхода;\n";
	cout << "|7 - для обратного(смешанный) обхода;\n";
	cout << "|8 - для проверки сбалансированности дерева;\n";
	cout << "|0 - для выхода:\n";
	cout << "\\___________________________________________/" << endl;
	cout << "Ваш выбор: ";

	do {
		choice = Correct_Input_Integer();

		switch (choice) {
		case 1: {
			int x;
			cout << "Введите число: "; x = Correct_Input_Integer();
			tree = input(tree, x);
			break;
		}
		case 2: {
			int x;
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Введите число: "; x = Correct_Input_Integer();
			tree = del(tree, x);
			break;
		}
		case 3: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Вывод:" << endl;
			show(tree, 0);
			break;
		}
		case 4: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Очистка..." << endl;
			tClear(tree);
			tree = nullptr;
			break;
		}
		case 5: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Прямой обход:" << endl;
			Directbypass(tree);
			break;
		}
		case 6: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Симметричный обход:" << endl;
			Symmetricbypass(tree);
			break;
		}
		case 7: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Обратный обход:" << endl;
			Reversebypass(tree);
			break;
		}
		case 8: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			if (isBalanced(tree)) cout << "Дерево сбалансированное!" << endl;
			else cout << "Дерево не сбалансированное!" << endl;
			break;
		}
		}
		if (choice) cout << "\nЧего желаете? --> ";
	} while (choice);
}

void show(tNode* tree, int space) {
	if (tree) {
		show(tree->left, space + 5);
		for (int i = 0; i < space; i++) {
			cout << " ";
		}
		cout << tree->data << endl;
		show(tree->right, space + 5);
	}
}

tNode* input(tNode* tree, int x) {
	if (!tree) {
		tree = new tNode;
		tree->data = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (x < tree->data) {
		tree->left = input(tree->left, x);
	}
	else {
		tree->right = input(tree->right, x);
	}
	return(tree);
}

tNode* del(tNode* tree, int x) {
	tNode* Del, * Prev_del, * R, * Prev_r;

	Del = tree;
	Prev_del = NULL;
	while (Del && Del->data != x) {
		Prev_del = Del;
		if (Del->data > x) Del = Del->left;
		else Del = Del->right;
	}

	if (!Del) {
		cout << "Элемент не найден!" << endl;
		return tree;
	}
	if (!Del->right) R = Del->left;
	else if (!Del->left) R = Del->right;
	else {
		Prev_r = Del;
		R = Del->left;
		while (R->right) {
			Prev_r = R;
			R = R->right;
		}
		if (Prev_r == Del) R->right = Del->right;
		else {
			R->right = Del->right;
			Prev_r->right = R->left;
			R->left = Prev_r;
		}
	}

	if (Del == tree) tree = R;
	else if (Del->data < Prev_del->data) Prev_del->left = R;
	else Prev_del->right = R;

	cout << "Удален элемент с ключом: " << Del->data << endl;
	delete Del;
	return tree;
}

void tClear(tNode* tree) {
	if (tree) {
		tClear(tree->left);
		tClear(tree->right);
		delete tree;
	}
}

void Directbypass(tNode* tree) {
	if (tree) {
		cout << tree->data << " ";
		Directbypass(tree->left);
		Directbypass(tree->right);
	}
}

void Symmetricbypass(tNode* tree) {
	if (tree) {
		Symmetricbypass(tree->left);
		cout << tree->data << " ";
		Symmetricbypass(tree->right);
	}
}

void Reversebypass(tNode* tree) {
	if (tree) {
		Reversebypass(tree->left);
		Reversebypass(tree->right);
		cout << tree->data << " ";
	}
}

int Depth(tNode* tree)
{
	if (tree != NULL)
	{
		int A = Depth(tree->left);
		int B = Depth(tree->right);
		if (A > B) return A + 1;
		else return B + 1;
	}
	else return 0;
}

bool isBalanced(tNode* tree) {
	if (!tree) return true;
	else {
		if (isBalanced(tree->left) && isBalanced(tree->right)) {
			int left = Depth(tree->left);
			int right = Depth(tree->right);
			if (abs(left - right) == 1 || left == right) return true;
			else return false;
		}
		return false;
	}
}


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