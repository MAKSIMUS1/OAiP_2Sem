#include <iostream>
#include "myStack_2.h"
#include <fstream>
using namespace std;
ofstream fout;
ifstream fin;
void push(int x, Stack* myStk)   //���������� �������� � � ����	
{
	Stack* e = new Stack;    //��������� ������ ��� ������ ��������
	e->data = x;             //������ �������� x � ���� e 
	e->next = myStk->head;   //������� ������� �� ��������� ������� 
	myStk->head = e;         //����� ������� �� ������� ������
}
int pop(Stack* myStk)   //���������� (��������) �������� �� �����
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
		return -1;               //���� ���� ���� - ������� -1 
	}
	else
	{
		Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk->head = myStk->head->next; //������� �������
		delete e;                        //�������� ��������� ����������
		return a;                        //������� �������� ���������� ��������
	}
}
void show(Stack* myStk)    //����� �����
{
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	bool work = false;
	int a;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		cout << a << "-->";
		e = e->next;
		work = true;
	}
	if (work)
		cout << "����� �����!" << endl;
}
void clear(Stack* myStk)
{
	if (myStk->head == NULL)
	{
		cout << "���� ����!" << endl;
	}
	else
	{
		while (myStk->head != NULL) {
			Stack* e = myStk->head;   //� - ���������� ��� �������� ������ ��������
			myStk->head = myStk->head->next; //������� �������
			delete e;//�������� ��������� ����������
		}
	}
	cout << "������� ���������!" << endl;
}
void clear_sp(Stack* myStk)
{
	bool pr = false;
	Stack* e = myStk->head;    //����������� ��������� �� ������� �����
	bool work = false;
	int a = 0, b = 1;
	if (e == NULL)
		cout << "���� ����!" << endl;
	while (e != NULL)
	{
		a = e->data;          //������ �������� � ���������� a 
		e = e->next;
		if (e != NULL) {
			b = e->data;
			if (a == b)
				pr = true;
		}
		a = 0;
		b = 1;
	}
	if (pr)
		printf("����� ������� ����.\n");
	else
		printf("������ �������� ���!\n");
}

void toFile(Stack* myStk)
{
	Stack* e = myStk->head;
	fout.open("file.txt");
	if (fout.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	if (e == NULL)
		cout << "���� ����! � ���� ������ �������� �� �����!" << endl;
	while (e != NULL)
	{
		fout << e->data << " ";
		e = e->next;
	}
	fout.close();
	cout << "������ � ���� ��������� �������!" << endl;
}
int fromFile(Stack* myStk)
{
	fin.open("file.txt");
	int value;
	fin >> value;
	if (fin.eof()) {
		fin.close();
		return -1;
	}
	Stack* Stkfile = new Stack;
	Stkfile->data = value;
	myStk->head = Stkfile;
	while (true) {
		fin >> value;
		if (fin.eof()) {
			break;
		}
		Stkfile->next = new Stack;
		Stkfile = Stkfile->next;
		Stkfile->data = value;
	}
	Stkfile->next = NULL;
	fin.close();
	return 1;
}
//���������� ���� integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) //���� proverka_na_minus = 1, ������ ������ ������ �����. ���� proverka_na_minus = 2, ������ ������ ������ �����.����
	{ //���� proverka_2 = 1, ������ ���� ��������.
		cin.ignore(cin.rdbuf()->in_avail());
		proverka_2 = 0;
		gets_s(ch);//���� proverka_2 = 0, ������ ���� ������ � �� ����������� ���� � ��������� � int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//���� ������ ������ �����, �� ����� ���� �������� ������� �������
			for (int i = 1; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		if (proverka_na_minus == 2)//���� ������ ������ �����, �� ����� �������� ����� �����
			for (int i = 0; i < strlen(ch); i++)
				if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9') {
					proverka_2 = 1;
					break;
				}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("�������� ����!\n������� ��� ���: ");
		if (proverka_2 == 0)
			proverka = 1;
	}
	value = atoi(ch);
	return value;
}