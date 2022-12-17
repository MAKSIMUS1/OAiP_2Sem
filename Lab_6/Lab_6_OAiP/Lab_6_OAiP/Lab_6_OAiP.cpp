//Создать список, содержащий элементы вещественного типа. 
//Найти среднее значение отрицательных элементов.
#include <iostream>
#include <fstream>
#include <sstream>
#include <iterator>
#define clc system("cls")
using namespace std;

struct list
{
	char symbol;
	list* next;
};

ofstream fout;
ifstream fin;

int Correct_Input_Integer();
void insert(list*& p, char value);	//Добавление символа в начало списка
void printList(list* p);			//Вывод списка 
void toFile(list*&);				//Запись в файл
void fromFile(list*&);				//Считывание из файла
void menu(void);					//Вывод меню 
char del(list*& p, char value);		//Удаление символа
bool IsEmpty(list*);				//Список пустой?
void find(list* p, char value);		//Поиск


int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int choice;
	char value;
	menu();    // вывести меню 
	cout << " ? ";
	choice = Correct_Input_Integer();
	while (choice != 9)
	{
		switch (choice)
		{
		case 1:  	cout << "Введите символ: ";
			cin >> value;
			insert(first, value);
			break;
		case 2:
			if (!IsEmpty(first)) // удалить число из списка
			{
				cout << "Введите символ, который хотите удалить: ";
				cin >> value;
				if (del(first, value))
					cout << "Удален символ " << value << endl;
				else
					cout << "Символ не найден!" << endl;
			}
			else
				cout << "Список пуст" << endl;
			break;
		case 3:    printList(first);
			break;
		case 4:
			cout << "Введите символ, который хотите найти: ";
			cin >> value;
			find(first, value);
			cout << endl;
			break;
		case 5:
			toFile(first);
			break;
		case 6:
			fromFile(first);
			break;
		default:   
			cout << "Неправильный выбор" << endl;
			cin.clear();
			break;
		}
		cout << "?  ";
		choice = Correct_Input_Integer();
	}
	return 0;
}
void menu(void)     //Вывод меню 
{
	printf("Сделайте выбор:\n");
	printf(" 1 - Ввод символа\n");
	printf(" 2 - Удаление символа\n");
	printf(" 3 - Вывести символы\n");
	printf(" 4 - Поиск элемента\n");
	printf(" 5 - Запись списка в файл\n");
	printf(" 6 - Вывод списка из файла\n");
	printf(" 9 - Выход\n");
}

void insert(list*& p, char value) //Добавление символа в начало списка
{
	list* newP = new list;
	if (newP != NULL)     //есть ли место?  
	{
		newP->symbol = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "Операция добавления не выполнена" << endl;
}

void printList(list* p)  //Вывод списка 
{
	if (p == NULL)
		cout << "Список пуст" << endl;
	else
	{
		cout << "Список:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->symbol;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* first = p;
	list buf;
	fout.open("Var4.txt");
	if (fout.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			fout << p->symbol << " ";
			p = p->next;
		}
	}
	fout.close();
	fin.open("Var4.txt");
	stringstream stream;													  // rdbuf() просто возвращает указатель на базовый объект basic_streambuf для данного объекта[io]stream.
	stream << fin.rdbuf();                                                    // читаем буфер
	string str = stream.str();
	fin.close();
	string::size_type size = str.size();									  // получение размера строки
	if (size > 0) {
		str.erase(size - 1, 1);                                               // удаление последнего символа, если строка не пустая
	}
	fout.open("Var4.txt");													  // ostream_iterator — это итератор вывода. Он применяется для вывода элементов.
	copy(str.begin(), str.end(), ostream_iterator<char>(fout, ""));			  // копирование новой строки (без последнего символа) в файл
	fout.close();															  // После ostream_iterator должен стоять <тип данных> выводимых элементов.
	cout << endl << "Список записан в файл Var4.txt" << endl;
	p = first;
}

void fromFile(list*& p)          //Считывание из файла
{
	fin.open("Var4.txt");
	char value;
	fin >> value;
	if (fin.eof()) {
		p = NULL;
		fin.close();
		return;
	}

	list* first = new list;
	first->symbol = value;
	p = first;

	while (true) {
		fin >> value;
		if (fin.eof()) {
			break;
		}
		first->next = new list;
		first = first->next;
		first->symbol = value;
	}
	first->next = NULL;
	fin.close();
	cout << endl << "Список считан из файла Var4.txt" << endl;
}

char del(list*& p, char value[])	//Удаление символа
{
	while (p != NULL) {
		list* previous, * current, * temp;
		if (strcmp(value, ) == 0value == p->symbol) {	//(*p).symbol==value)
			temp = p;
			p = p->next;    // отсоединить узел 
			delete temp;      //освободить отсоединенный узел 
			return value;
		}
		else
		{
			previous = p;
			current = p->next;
			while (current != NULL && current->symbol != value)
			{
				previous = current;
				current = current->next; // перейти к следующему 
			}
			if (current != NULL)
			{
				temp = current;
				previous->next = current->next;
				delete temp;
				return value;
			}
		}
		return 0;
	}
	return 0;
}

bool IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
	return p == NULL;
}

void find(list* p, char value) {
	bool work = false;
	if (p == NULL) {
		cout << endl << "Список пуст" << endl;
	}
	else {
		while (p != NULL) {
			if (p->symbol == value && p->next != NULL) {
				cout << endl << "Элемент \"" << p->symbol << "\" найден.";
				cout << " Следующий элемент списка - \"" << p->next->symbol << "\"" << endl;
				work = true;
				break;
			}
			if (p->symbol == value && p->next == NULL) {
				cout << endl << "Элемент \"" << p->symbol << "\" найден.";
				cout << " Следующий элемент списка NULL" << endl;
				work = true;
				break;
			}
			p = p->next;
		}
	}
	if (!work) {
		cout << endl << "Элемент не найден!" << endl;
	}
}
//Корректный ввод integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

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