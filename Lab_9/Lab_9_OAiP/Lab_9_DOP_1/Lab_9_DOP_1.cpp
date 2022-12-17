#include <iostream>
#include <fstream>
using namespace std;
const unsigned int NAME_SIZE = 30;
const unsigned int CITY_SIZE = 20;

int counter = 0;
struct Address
{
	char name[NAME_SIZE];
	char city[CITY_SIZE];
	Address* next;
	Address* prev;
};
typedef Address* PAddress;
//-----------------------------------------------------------
int menu(void)
{
	char s[80];  int c;
	cout << endl;
	cout << "1 - Ввод имени" << endl;
	cout << "2 - Удаление имени" << endl;
	cout << "3 - Вывод на экран" << endl;
	cout << "4 - Поиск" << endl;
	cout << "5 - Запись в файл" << endl;
	cout << "6 - Считывание из файла" << endl;
	cout << "7 - Удаление k элементов с конца" << endl;
	cout << "8 - Удаления К первых элементов списка" << endl;
	cout << "9 - Aункция возвращения истинного значения, если список пуст и возвращение ложного в противном случае " << endl;
	cout << "10 - Выход" << endl;
	cout << endl;
	do
	{
		cout << "Ваш выбор: ";
		cin.sync();
		gets_s(s);
		cout << endl;
		c = atoi(s);
	} while (c < 0 || c > 10);
	return c;
}
//-----------------------------------------------------------
void insert(Address* e, Address** phead, Address** plast) //Добавление в конец списка
{
	Address* p = *plast;
	if (*plast == NULL)
	{
		e->next = NULL;
		e->prev = NULL;
		*plast = e;
		*phead = e;
		counter++;
		return;
	}
	else
	{
		p->next = e;
		e->next = NULL;
		e->prev = p;
		*plast = e;
		counter++;
	}
}
//-----------------------------------------------------------
Address* setElement()      // Создание элемента и ввод его значений с клавиатуры 
{
	Address* temp = new  Address();
	if (!temp)
	{
		std::cerr << "Ошибка выделения памяти памяти";
		return NULL;
	}
	cout << "Введите имя: ";
	cin.getline(temp->name, NAME_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	cout << "Введите город: ";
	cin.getline(temp->city, CITY_SIZE - 1, '\n');
	cin.ignore(cin.rdbuf()->in_avail());
	cin.clear();
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}
//-----------------------------------------------------------
void outputList(Address** phead, Address** plast)      //Вывод списка на экран
{
	Address* t = *phead;
	while (t)
	{
		cout << t->name << ' ' << t->city << endl;
		t = t->next;
	}
	cout << "" << endl;
}
//-----------------------------------------------------------
void find(char name[NAME_SIZE], Address** phead)    // Поиск имени в списке
{
	Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name)) break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
		cout << t->name << ' ' << t->city << endl;
}
//-----------------------------------------------------------
void delet(char name[NAME_SIZE], Address** phead, Address** plast)  // Удаление имени 
{
	struct Address* t = *phead;
	while (t)
	{
		if (!strcmp(name, t->name))  break;
		t = t->next;
	}
	if (!t)
		cerr << "Имя не найдено" << endl;
	else
	{
		if (*phead == t)
		{
			*phead = t->next;
			if (*phead)
				(*phead)->prev = NULL;
			else
				*plast = NULL;
		}
		else
		{
			t->prev->next = t->next;
			if (t != *plast)
				t->next->prev = t->prev;
			else
				*plast = t->prev;
		}
		delete t;
		cout << "Элемент удален" << endl;
		counter--;
	}
}
void writeToFile(Address** phead)       //Запись в файл
{
	struct Address* t = *phead;
	FILE* fp;
	errno_t err = fopen_s(&fp, "List.txt", "w");	//wb-Создает двоичный файл для записи.
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	cout << "Сохранение в файл" << endl;
	while (t)
	{
		fwrite(t, sizeof(struct Address), 1, fp);
		t = t->next;
	}
	fclose(fp);
}
//-----------------------------------------------------------
//returnN – функция возвращения истинного значения, если список пуст и возвращение ложного в противном случае
bool returnN(Address** phead, Address** plast) {
	if (*phead == NULL && *plast == NULL) {
		cout << "Список пуст" << endl;
		return true;
	}
	else {
		cout << "Список не пуст" << endl;
		return false;
	}
}
void readFromFile(Address** phead, Address** plast)          //Считывание из файла
{
	struct Address* t;
	FILE* fp;
	errno_t err = fopen_s(&fp, "List.txt", "r");	//rb-Открывает двоичный файл для чтения.
	if (err)
	{
		cerr << "Файл не открывается" << endl;
		exit(1);
	}
	while (*phead)
	{
		*plast = (*phead)->next;
		delete* phead;
		*phead = *plast;
	}
	*phead = *plast = NULL;
	counter = 0;
	cout << "Загрузка из файла" << endl;
	while (!feof(fp))
	{
		t = new Address();
		if (!t)
		{
			cerr << "Ошибка выделения памяти" << endl;
			return;
		}
		if (1 != fread(t, sizeof(struct Address), 1, fp)) break;
		insert(t, phead, plast);
	}
	fclose(fp);
}

void deleteKFirst(int k, Address** phead, Address** plast) {
	if (k <= 0) {
		cout << "Число отрицательное или равно нулю!" << endl;
	}
	else {
		while (k != 0) {
			struct Address* t = *phead;
			if (counter == 0) {
				cout << "Список пуст! Число удаляемых элементов было слишком много!" << endl;
				break;
			}
			if (*plast == t)
			{
				*plast = t->prev;
				if (*plast) {
					(*plast)->next = NULL;
					cout << "Элемент удален" << endl;
				}
				else {
					*phead = NULL;
					cout << "Элемент удален" << endl;
				}
				counter--;
				k--;
			}
			else {
				t->next->prev = t->prev;
				if (t != *phead)
					t->prev->next = t->next;
				else
					*phead = t->next;
				delete t;
				cout << "Элемент удален" << endl;
				counter--;
				k--;
			}
		}
	}

}
void deletk(int k, Address** phead, Address** plast)  // Удаление имени {	struct Address *t = *phead;
{

	if (k <= 0) {
		cout << "Число отрицательное или равно нулю!" << endl;
	}
	else {
		while (k != 0) {
			struct Address* t = *plast;
			if (counter == 0) {
				cout << "Список пуст! Число удаляемых элементов было слишком много!" << endl;
				break;
			}
			if (*phead == t)
			{
				*phead = t->next;
				if (*phead) {
					(*phead)->prev = NULL;
					cout << "Элемент удален" << endl;
				}
				else {
					*plast = NULL;
					cout << "Элемент удален" << endl;
				}
				counter--;
				k--;
			}
			else {
				t->prev->next = t->next;
				if (t != *plast)
					t->next->prev = t->prev;
				else
					*plast = t->prev;
				delete t;
				cout << "Элемент удален" << endl;
				counter--;
				k--;
			}
		}
	}

}
//-----------------------------------------------------------
int main(void)
{
	Address* head = NULL;
	Address* last = NULL;
	int k;
	setlocale(LC_CTYPE, "Rus");
	while (true)
	{
		switch (menu())
		{
		case 1:  insert(setElement(), &head, &last);
			break;
		case 2: {	  char dname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(dname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			delet(dname, &head, &last);
		}
			  break;
		case 3:  outputList(&head, &last);
			break;
		case 4: {	  char fname[NAME_SIZE];
			cout << "Введите имя: ";
			cin.getline(fname, NAME_SIZE - 1, '\n');
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			find(fname, &head);
		}
			  break;
		case 5:  writeToFile(&head);
			break;
		case 6:  readFromFile(&head, &last);
			break;
		case 7:	cout << "Введите число удаляемых элементов с конца: ";
			cin >> k;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			deletk(k, &head, &last);
			break;
		case 8:	cout << "Введите число удаляемых элементов с начала: ";
			cin >> k;
			cin.ignore(cin.rdbuf()->in_avail());
			cin.sync();
			deleteKFirst(k, &head, &last);
			break;
		case 9: returnN(&head, &last);
		case 10:  exit(0);
		default: exit(1);
		}
	}
	return 0;
}
