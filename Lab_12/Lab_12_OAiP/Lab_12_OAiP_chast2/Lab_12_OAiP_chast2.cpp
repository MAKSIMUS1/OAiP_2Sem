#include<iostream>
using namespace std;

int arr[100];
int length_arr = 0;

struct tNode {
	int number{};
	string st_owner, st_tariff;
	tNode* left{}, * right{};
};

void show(tNode*);
tNode* input(tNode*, string, int, int);
void search(tNode*, int);
void best_tariff(tNode*, int*);

int Correct_Input_Integer();


int main() {
	setlocale(LC_ALL, "RUS");
	tNode* tree = nullptr;
	int choice;
	cout << " ____________________Меню____________________" << endl;
	cout << "/1  - для добавления абонента;\n";
	cout << "|2  - для поиска абонента;	\n";
	cout << "|3  - для вывода абонентов;\n";
	cout << "|0  - для выхода;\n";
	cout << "\\___________________________________________/" << endl;
	cout << "Ваш выбор: ";

	do {
		choice = Correct_Input_Integer();

		switch (choice) {
		case 1: {
			int phone_number, tariff;
			string owner;
			cout << "Введите идентификатор: ";
			bool prov_arr = true;
			while (prov_arr) {
				prov_arr = false;
				phone_number = Correct_Input_Integer();
				for (int i = 0; i < length_arr; i++) {
					if (phone_number == arr[i]) {
						prov_arr = true;
						cout << "Такой идентификатор уже есть." << endl;
						break;
					}
				}
			}
			arr[length_arr] = phone_number;
			length_arr++;
			cout << "Введите имя: ";
			cin >> owner;
			cout << "Введите тариф (1-Эконом, 2-Рабочий, 3-VIP): ";
			bool prov = true;
			while (prov) {
				tariff = Correct_Input_Integer();
				if (tariff == 1 || tariff == 2 || tariff == 3)
					prov = false;
				else
					cout << "Такого варианта нет." << endl;
			}
			tree = input(tree, owner, phone_number, tariff);
			break;
		}
		case 2: {
			int phone_number;
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Введите идентификатор: ";
			phone_number = Correct_Input_Integer();
			search(tree, phone_number);
			break;
		}
		case 3: {
			if (!tree) {
				cout << "Пусто." << endl;
				break;
			}
			cout << "Вывод:" << endl;
			show(tree);
			break;
		}
		}
		if (choice) cout << "\nЧего желаете? --> ";
	} while (choice);
}

void show(tNode* tree) {
	if (tree) {
		show(tree->right);
		cout << "____________________________________" << endl;
		cout << "Идентификатор: " << tree->number << endl;
		cout << "Владелец: " << tree->st_owner << endl;
		cout << "Тариф: " << tree->st_tariff << endl;
		cout << "////////////////////////////////////" << endl;
		show(tree->left);
	}
}

tNode* input(tNode* tree, string owner, int phone_number, int tariff) {
	if (!tree) {
		tree = new tNode;
		tree->number = phone_number;
		if (tariff == 1)
			tree->st_tariff = "Эконом";
		if (tariff == 2)
			tree->st_tariff = "Рабочий";
		if (tariff == 3)
			tree->st_tariff = "VIP";
		tree->st_owner = owner;
		tree->left = NULL;
		tree->right = NULL;
	}
	else if (phone_number < tree->number) {
		tree->left = input(tree->left, owner, phone_number, tariff);
	}
	else {
		tree->right = input(tree->right, owner, phone_number, tariff);
	}
	return(tree);
}

void search(tNode* tree, int phone_number) {
	if (tree) {
		if (tree->number == phone_number) {
			cout << "____________________________________" << endl;
			cout << "Телефон: " << tree->number << endl;
			cout << "Владелец: " << tree->st_owner << endl;
			cout << "Тариф: " << tree->st_tariff << endl;
			cout << "////////////////////////////////////" << endl;
		}
		else {
			if (phone_number > tree->number) search(tree->right, phone_number);
			else search(tree->left, phone_number);
		}
	}
	else cout << "Нет такого номера!" << endl;
}

void best_tariff(tNode* tree, int* mass) {
	if (tree) {
		if (tree->st_tariff == "Эконом")
			mass[0]++;
		if (tree->st_tariff == "Рабочий")
			mass[1]++;
		if (tree->st_tariff == "VIP")
			mass[2]++;
		best_tariff(tree->left, mass);
		best_tariff(tree->right, mass);
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