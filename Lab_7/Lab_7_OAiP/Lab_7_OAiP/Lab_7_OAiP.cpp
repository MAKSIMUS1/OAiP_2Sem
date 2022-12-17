//Дана величина a строкового типа из четного количества символов. 
//Получить и напечатать величину b, состоящую из символов первой половины величины a, записанных в обратном порядке, после которых идут символы второй половины величины a, также записанные в обратном порядке 
//(например, при а = “привет” b должно быть равно «ипртев»).
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Stack
	{
		char data;
		Stack* head;
		Stack* next;
	};
	string str;
	printf("Введите строку : ");
	cin >> str;
	printf("Полученная строка: ");
	Stack* first = new Stack;				//делим слово пополам и переворачиваем первую половину
	first->head = NULL;
	for (int i = 0; i < str.length() / 2; i++) {
		Stack* el = new Stack;
		el->data = str[i];
		el->next = first->head;
		first->head = el;
	}
	Stack* el = new Stack;
	el = first->head;
	while (el != NULL)						//выводим перевернутую часть
	{
		cout << el->data;
		el = el->next;
	}
	Stack* second = new Stack;				//делим слово пополам и переворачиваем (часть 2)
	second->head = NULL;
	for (int i = str.length() / 2; i < str.length(); i++) {
		Stack* el = new Stack;
		el->data = str[i];
		el->next = second->head;
		second->head = el;
	}
	el = new Stack;
	el = second->head;
	while (el != NULL)
	{
		cout << el->data;
		el = el->next;
	}
	cout << endl;
}