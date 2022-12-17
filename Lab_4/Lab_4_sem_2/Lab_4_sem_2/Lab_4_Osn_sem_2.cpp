//������. ������� 9. 
//	��������. 
//	�.�.�., ���� �����������, �������������, ������, ���������, ������� ����. ����� �� �������.
#include <iostream>                  
#include <stdio.h>  
#include <fstream>
#include <windows.h>
# define _CRT_SECURE_NO_WARNINGS
# define str_len 30                               
# define size 30  
using namespace std;
//�������:
void enter_new();//	���� ��������� ��������� � ����������
void out();// ����� ��������� ��������� � ���������� ����
void del();// �������� �������� ����������������� ����������
void search();//����� ����������
void out_file();//	������ ���������� � ����
void in_file();// ������ ������ �� �����
//������� ��������:
float Correct_Input_Float();//���������� ���� ������ �� ����� �����
int Correct_Input_Integer();//���������� ���� ������ ����� �����

struct Student
{
	char name_familiya[str_len];
	char name[str_len];
	char name_otchestvo[str_len];
	char receipt_date[str_len];
	char speciality[str_len];
	int group;
	char faculty[str_len];
	float GPA;
};
struct Student list_of_student[size];
struct Student bad;// ��� ��������
int current_size = 0; 
int choice;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	do
	{
		printf("-------------------------------------------------------\n");
		printf("1-���� ��������� ��������� � ����������.\n");
		printf("2-����� ��������� ��������� � ���������� ����.\n");
		printf("3-�������� �������� ����������������� ����������.\n");
		printf("4-����� ����������.\n");
		printf("5-������ ���������� � ����.\n");
		printf("6-������ ������ �� �����.\n");
		printf("7-�����.\n");
		printf("-------------------------------------------------------\n");
		printf("����: ");
		do {
			choice = Correct_Input_Integer();
			if (choice <= 0 || choice >= 8)
				printf("������ �������� ���!\n������� ��� ���: ");
		} while (choice <= 0 || choice >= 8);
		switch (choice)
		{
		case 1:  enter_new(); break;
		case 2:  out(); break;
		case 3:  del(); break;
		case 4:  search(); break;
		case 5:  out_file(); break;
		case 6:  in_file();	break;
		}
	} while (choice != 7);
}
void enter_new()
{
	bool pr = false;
	printf("���� ����������:\n");
	if (current_size < size)
	{
		printf("������� ����� %d", current_size + 1);
		printf("\n�������: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].name_familiya);
			for (int k = 0; k < strlen(list_of_student[current_size].name_familiya); k++)
				if ((list_of_student[current_size].name_familiya[k] < 'A' || list_of_student[current_size].name_familiya[k] > 'Z') && 
					(list_of_student[current_size].name_familiya[k] < 'a' || list_of_student[current_size].name_familiya[k] > 'z') && 
					(list_of_student[current_size].name_familiya[k] < '�' || list_of_student[current_size].name_familiya[k] > '�') && 
					(list_of_student[current_size].name_familiya[k] != ' '))
					pr = true;
			if (list_of_student[current_size].name_familiya[0] == '\0')
				pr = true;
			if (pr == true)
				printf("����������� ����, ����� ������� ������ �����!\n������� ��� ���: ");
		} while (pr == true);
		printf("���: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].name);
			for (int k = 0; k < strlen(list_of_student[current_size].name); k++)
				if ((list_of_student[current_size].name[k] < 'A' || list_of_student[current_size].name[k] > 'Z') && 
					(list_of_student[current_size].name[k] < 'a' || list_of_student[current_size].name[k] > 'z') && 
					(list_of_student[current_size].name[k] < '�' || list_of_student[current_size].name[k] > '�') && 
					(list_of_student[current_size].name[k] != ' '))
					pr = true;
			if (list_of_student[current_size].name[0] == '\0')
				pr = true;
			if (pr == true)
				printf("����������� ����, ����� ������� ������ �����!\n������� ��� ���: ");
		} while (pr == true);
		printf("��������: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].name_otchestvo);
			for (int k = 0; k < strlen(list_of_student[current_size].name_otchestvo); k++)
				if ((list_of_student[current_size].name_otchestvo[k] < 'A' || list_of_student[current_size].name_otchestvo[k] > 'Z') &&
					(list_of_student[current_size].name_otchestvo[k] < 'a' || list_of_student[current_size].name_otchestvo[k] > 'z') &&
					(list_of_student[current_size].name_otchestvo[k] < '�' || list_of_student[current_size].name_otchestvo[k] > '�') &&
					(list_of_student[current_size].name_otchestvo[k] != ' '))
					pr = true;
			if (list_of_student[current_size].name_otchestvo[0] == '\0')
				pr = true;
			if (pr == true)
				printf("����������� ����, ����� ������� ������ �����!\n������� ��� ���: ");
		} while (pr == true);
		printf("���� �����������. ");
		int year, month, day;
		bool proverka = true;
		int data_int = 0;
		while (proverka)
		{
			printf("������� ���� ����������� � ������� ��������: ");
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].receipt_date);
			if (list_of_student[current_size].receipt_date[8] == '\0')
			{
				if ((list_of_student[current_size].receipt_date[0] >= '0' || list_of_student[current_size].receipt_date[0] < '4') &&
					(list_of_student[current_size].receipt_date[1] >= '0' || list_of_student[current_size].receipt_date[1] <= '9') &&
					(list_of_student[current_size].receipt_date[2] >= '0' || list_of_student[current_size].receipt_date[2] < '1') &&
					(list_of_student[current_size].receipt_date[3] >= '0' || list_of_student[current_size].receipt_date[3] <= '9') &&
					(list_of_student[current_size].receipt_date[4] >= '0' || list_of_student[current_size].receipt_date[4] <= '9') &&
					(list_of_student[current_size].receipt_date[5] >= '0' || list_of_student[current_size].receipt_date[5] <= '9') &&
					(list_of_student[current_size].receipt_date[6] >= '0' || list_of_student[current_size].receipt_date[6] <= '9') &&
					(list_of_student[current_size].receipt_date[7] >= '0' || list_of_student[current_size].receipt_date[7] <= '9'))
				{
					data_int = atoi(list_of_student[current_size].receipt_date);
					if (data_int >= 1010001 && data_int <= 31129999)
					{
						year = data_int % 10000;
						month = (data_int / 10000) % 100;
						day = data_int / 1000000;
						if (month < 13 && month > 0)
						{
							if (year % 4 == 0 && year % 100 != 0)
							{
								if ((month == 2 && day < 30) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
								{
									proverka = false;
								}
								else
									printf("������������ ����\n");
							}
							else
							{
								if ((month == 2 && day < 29) || (month % 2 == 0 && month != 2 && day < 31) || (month % 2 == 1 && day < 32))
								{
									proverka = false;
								}
								else
									printf("������������ ����\n");
							}
						}
						else
							printf("������������ ����\n");
					}
					else
						printf("������������ ����\n");
				}
			}
			else
				printf("������������ ����\n");
		}
		printf("�������������: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].speciality);
			for (int k = 0; k < strlen(list_of_student[current_size].speciality); k++)
				if ((list_of_student[current_size].speciality[k] < 'A' || list_of_student[current_size].speciality[k] > 'Z') &&
					(list_of_student[current_size].speciality[k] < 'a' || list_of_student[current_size].speciality[k] > 'z') &&
					(list_of_student[current_size].speciality[k] < '�' || list_of_student[current_size].speciality[k] > '�') &&
					(list_of_student[current_size].speciality[k] != ' '))
					pr = true;
			if (list_of_student[current_size].speciality[0] == '\0')
				pr = true;
			if (pr == true)
				printf("����������� ����, ����� ������� ������ �����!\n������� ��� ���: ");
		} while (pr == true);
		printf("������: ");
		list_of_student[current_size].group = Correct_Input_Integer();
		printf("���������: ");
		do {
			pr = false;
			cin.ignore(cin.rdbuf()->in_avail());
			gets_s(list_of_student[current_size].faculty);
			for (int k = 0; k < strlen(list_of_student[current_size].faculty); k++)
				if ((list_of_student[current_size].faculty[k] < 'A' || list_of_student[current_size].faculty[k] > 'Z') &&
					(list_of_student[current_size].faculty[k] < 'a' || list_of_student[current_size].faculty[k] > 'z') &&
					(list_of_student[current_size].faculty[k] < '�' || list_of_student[current_size].faculty[k] > '�') &&
					(list_of_student[current_size].faculty[k] != ' '))
					pr = true;
			if (list_of_student[current_size].faculty[0] == '\0')
				pr = true;
			if (pr == true)
				printf("����������� ����, ����� ������� ������ �����!\n������� ��� ���: ");
		} while (pr == true);
		printf("������� ����(������ 2 ����� ����� �������): ");
		list_of_student[current_size].GPA = Correct_Input_Float();
		current_size++;
	}
	else
		printf("������� ������������ ���-�� �����.");
	printf("��� ������?\n");
}
void out()
{
	int sw, n;
	bool pr = true;
	printf("1-����� ����� ������.\n2-����� ���� �����.\n");
	do {
		scanf_s("%d", &sw);
		if (sw == 1 || sw == 2)
			pr = false;
		else
			printf("������������ �����! ��������� �������: ");
	} while (pr == true);
	if (sw == 1)
	{
		printf("����� ��������� ������ ");
		n = Correct_Input_Integer();
		if (n > 0 && n <= current_size) {
			printf("*****************************************************\n");
			printf("�������: %s\n", list_of_student[n - 1].name_familiya);
			printf("���: %s\n", list_of_student[n - 1].name);
			printf("��������: %s\n", list_of_student[n - 1].name_otchestvo);
			printf("���� �����������: %s\n", list_of_student[n - 1].receipt_date);
			printf("�������������: %s\n", list_of_student[n - 1].speciality);
			printf("������: %d\n", list_of_student[n - 1].group);
			printf("���������: %s\n", list_of_student[n - 1].faculty);
			printf("������� ����: %0.2f\n", list_of_student[n - 1].GPA);
			printf("*****************************************************\n");
		}
		else
			printf("��� ����� ������.\n");
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			printf("*****************************************************\n");
			printf("������� ����� %d\n", i + 1);
			printf("�������: %s\n", list_of_student[i].name_familiya);
			printf("���: %s\n", list_of_student[i].name);
			printf("��������: %s\n", list_of_student[i].name_otchestvo);
			printf("���� �����������: %s\n", list_of_student[i].receipt_date);
			printf("�������������: %s\n", list_of_student[i].speciality);
			printf("������: %d\n", list_of_student[i].group);
			printf("���������: %s\n", list_of_student[i].faculty);
			printf("������� ����: %0.2f\n", list_of_student[i].GPA);
			printf("*****************************************************\n");
		}
	}
	printf("��� ������?\n");
}
void del()
{
	int d;
	bool pr = true;
	printf("\n����� ��������, ������ �������� ����� ������� (��� �������� ������ ���� ��������� ������ 99): ");
	do {
		d = Correct_Input_Integer();
		if (d > 0 && d <= current_size || d == 99)
			pr = false;
		else
			printf("����� ������ ���!\n��������� �������: ");
	} while (pr == true);
	if (d != 99)
	{
		for (int de1 = (d - 1); de1 < current_size; de1++)
			list_of_student[de1] = list_of_student[de1 + 1];
		current_size = current_size - 1;
		printf("���� �������� ������ �������� ����� %d", d);
	}
	if (d == 99) {
		for (int i = 0; i < size; i++)
			list_of_student[i] = bad;
		printf("���� ��������� ������ ���� ���������.\n");
	}
	printf("��� ������?\n");
}
void search() {
	char search_familiya[str_len];
	char search_name[str_len];
	bool o = false;
	printf("������� ��� � ������� �������� ��������.\n");
	printf("���: ");
	cin >> search_name;
	printf("�������: ");
	cin >> search_familiya;
	for (int i = 0; i < current_size; i++)
		if ((strcmp(list_of_student[i].name_familiya, search_familiya) == 0) && (strcmp(list_of_student[i].name, search_name) == 0))
		{
			printf("��� ������� ����� %d.\n", i + 1);
			o = true;
		}
	if (o == false)
		printf("������� �� ������.\n");
	printf("��� ������?\n");
}
void out_file() {
	char naz[10] = "";
	int sw, n;
	printf("������� �������� �����(� �����������!): ");
	cin >> naz;

	ofstream fout(naz);
	
	bool pr = true;
	printf("1-����� ����� ������.\n2-����� ���� �����.\n");
	do {
		sw = Correct_Input_Integer();
		if (sw == 1 || sw == 2)
			pr = false;
		else
			printf("������������ �����! ��������� �������: ");
	} while (pr == true);

	if (sw == 1)
	{
		printf("����� ��������� ������ ");
		n = Correct_Input_Integer();
		if (n > 0 && n <= current_size) {
			fout << "�������: " << list_of_student[n - 1].name_familiya << endl;
			fout << "���: " << list_of_student[n - 1].name << endl;
			fout << "��������: " << list_of_student[n - 1].name_otchestvo << endl;
			fout << "���� �����������: " << list_of_student[n - 1].receipt_date << endl;
			fout << "�������������: " << list_of_student[n - 1].speciality << endl;
			fout << "������: " << list_of_student[n - 1].group << endl;
			fout << "���������: " << list_of_student[n - 1].faculty << endl;
			fout << "������� ����: " << list_of_student[n - 1].GPA << endl;
			printf("������ ����� %d ���� ��������.\n", n);
		}
		else
			printf("��� ����� ������.\n");
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_size; i++)
		{
			fout << "�������: " << list_of_student[i].name_familiya << endl;
			fout << "���: " << list_of_student[i].name << endl;
			fout << "��������: " << list_of_student[i].name_otchestvo << endl;
			fout << "���� �����������: " << list_of_student[i].receipt_date << endl;
			fout << "�������������: " << list_of_student[i].speciality << endl;
			fout << "������: " << list_of_student[i].group << endl;
			fout << "���������: " << list_of_student[i].faculty << endl;
			fout << "������� ����: " << list_of_student[i].GPA << endl;
		}
		printf("��� ������ ���� ���������.\n");
	}
	fout.close();
	printf("��� ������?\n");
}

void in_file() {
	char naz[15] = "";
	printf("������� �������� �����(� �����������!): ");
	cin >> naz;

	ifstream fin(naz);

	char buff[50];

	if (!fin.is_open())
		printf("���� �� ����� ���� ������!\n");
	else
	{
		for (int i = 0; i < 8; i++)
		{
			fin.getline(buff, 50); // ���������� ������ �� �����
			if (i == 0) {
				cout << "������� ";
				cout << buff << endl;
			}
			if (i == 1) {
				cout << "���: ";
				cout << buff << endl;
			}
			if (i == 2) {
				cout << "��������: ";
				cout << buff << endl;
			}
			if (i == 3) {
				cout << "���� �����������: ";
				cout << buff << endl;
			}
			if (i == 4) {
				cout << "������������: ";
				cout << buff << endl;
			}
			if (i == 5) {
				cout << "������: ";
				cout << buff << endl;
			}
			if (i == 6) {
				cout << "���������: ";
				cout << buff << endl;
			}
			if (i == 7) {
				cout << "������� ����: ";
				cout << buff << endl;
			}
		}
	}
	fin.close();
	printf("��� ������?\n");
}


//���������� ���� integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[11];

	while (proverka != 1) //���� proverka_na_minus = 1, ������ ������ ������ �����. ���� proverka_na_minus = 2, ������ ������ ������ �����.����
	{ //���� proverka_2 = 1, ������ ���� ��������.
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);//���� proverka_2 = 0, ������ ���� ������ � �� ����������� ���� � ��������� � int.
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//���� ������ ������ �����, �� ����� ���� �������� ������� �������
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)//���� ������ ������ �����, �� ����� �������� ����� �����
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] <= '0' || ch[i] >= '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
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

float Correct_Input_Float() {
	float value;
	int proverka = 0, proverka_2 = 0;
	char ch[30];

	while (proverka != 1) 
	{
		proverka_2 = 0;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[4] == '\0')
			if (ch[1] == '.')
				if ((ch[0] >= '0' && ch[0] <= '9') && (ch[2] >= '0' && ch[2] <= '9') && (ch[3] >= '0' && ch[3] <= '9'))
					proverka_2 = 1;
		cin.clear();
		if (proverka_2 == 0 || atof(ch) < 0 || atof(ch) > 10)
			printf("�������� ����!\n������� ��� ���: ");
		if (proverka_2 == 1 && atof(ch) >= 0 && atof(ch) <= 10)
			proverka = 1;
	}
	value = atof(ch);
	return value;
}