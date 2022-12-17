#include <iostream>
#include "myStack_3.h"
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
			int a = myStk->head->data;   //������ ����� �� ���� data � ���������� a 
			myStk->head = myStk->head->next; //������� �������
			delete e;//�������� ��������� ����������
		}
	}
	cout << "������� ���������!" << endl;
}
void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2)
{
	while (myStk1->head != NULL) {
		Stack* e1 = myStk1->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk1->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk1->head = myStk1->head->next; //������� �������
		delete e1;//�������� ��������� ����������
	}
	/////////////////
	while (myStk2->head != NULL) {
		Stack* e2 = myStk2->head;   //� - ���������� ��� �������� ������ ��������
		int a = myStk2->head->data;   //������ ����� �� ���� data � ���������� a 
		myStk2->head = myStk2->head->next; //������� �������
		delete e2;//�������� ��������� ����������
	}
	if (myStk->head == NULL)
		printf("���� ����.\n");
	else
	{
		Stack* e = myStk->head;    //����������� ��������� �� ������� �����
		bool work = false;
		int a;
		while (e != NULL)
		{
			a = e->data;          //������ �������� � ���������� a
			if (a > 0) {	// Stack1 �� ������ ���������

				Stack* e1 = new Stack;    //��������� ������ ��� ������ ��������
				e1->data = a;             //������ �������� x � ���� e 
				e1->next = myStk1->head;   //������� ������� �� ��������� ������� 
				myStk1->head = e1;         //����� ������� �� ������� ������
			}
			if (a < 0) {	// Stack2 �� ��������

				Stack* e2 = new Stack;    //��������� ������ ��� ������ ��������
				e2->data = a;             //������ �������� x � ���� e 
				e2->next = myStk2->head;   //������� ������� �� ��������� ������� 
				myStk2->head = e2;         //����� ������� �� ������� ������
			}
			e = e->next;
		}
		printf("���������� ����������.\n");
	}
}
void show_stacks(Stack* myStk1, Stack* myStk2) {
	Stack* e1 = myStk1->head;    //����������� ��������� �� ������� �����
	bool work = false;
	int a;
	if (e1 == NULL)
		cout << "���� Stack1 ����!" << endl;
	while (e1 != NULL)
	{
		a = e1->data;          //������ �������� � ���������� a 
		cout << a << "-->";
		e1 = e1->next;
		work = true;
	}
	if (work)
		cout << "����� ����� Stack1!" << endl;
	/////////////////////////////////////////
	Stack* e2 = myStk2->head;    //����������� ��������� �� ������� �����
	work = false;
	if (e2 == NULL)
		cout << "���� Stack2 ����!" << endl;
	while (e2 != NULL)
	{
		a = e2->data;          //������ �������� � ���������� a 
		cout << a << "-->";
		e2 = e2->next;
		work = true;
	}
	if (work)
		cout << "����� ����� Stack2!" << endl;
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