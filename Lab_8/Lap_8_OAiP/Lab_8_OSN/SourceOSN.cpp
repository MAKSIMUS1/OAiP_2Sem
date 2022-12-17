#include"Header2.h"
#include<iostream>
using namespace std;

void Queue::insert(float k) {
	if (rear == maxSize) cout << "������� ���������!" << endl;
	else
		arr[rear++] = k;
}

float Queue::remove() {
	if (!rear) {
		cout << "������� �����!" << endl;
		return NULL;
	}

	int temp = arr[front];
	for (int i = 0; i < rear - 1; i++)
		arr[i] = arr[i + 1];
	rear--;
	return temp;
}

int Queue::size() {
	return rear;
}

void Queue::display() {
	if (!rear) {
		cout << "������� �����!" << endl;
		return;
	}
	else
		for (int i = 0; i < rear; i++)
			cout << i + 1 << ") " << arr[i] << endl;
}

float Queue::findMax() {
	if (!rear) {
		cout << "������� �����!" << endl;
		return NULL;
	}
	else {
		float max = arr[0];
		for (int i = 0; i < rear; i++)
			if (arr[i] > max) 
				max = arr[i];
		return max;
	}
}

void Queue::cycle(float k) {
	while (arr[0] != k) {
		float temp = arr[0];
		for (int i = 0; i < rear - 1; i++) {
			arr[i] = arr[i + 1];
		}
		arr[rear - 1] = temp;
	}
}
//���������� ���� Float
float Correct_Input_Float()
{
	bool pr = false;
	bool minus = false;
	bool proverka = false;
	int proverka_na_minus = 0, proverka_tochka = 0;
	char ch[30];

	while (!pr)
	{
		proverka = false;
		proverka_na_minus = 0;
		proverka_tochka = 0;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(ch);
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka = true;
		if (proverka_na_minus == 1)//���� ������ ������ �����
		{
			for (int i = 1; i < strlen(ch); i++)
				if (ch[i] == ',')
					proverka_tochka++;
			if (proverka_tochka >= 2) {
				proverka = true;
			}
			if (proverka_tochka <= 1)
				for (int i = 1; i < strlen(ch); i++)
					if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9' && ch[i] != ',') {
						proverka = true;
					}
		}
		if (proverka_na_minus == 2)//���� ������ ������ �����
		{
			for (int i = 0; i < strlen(ch); i++)
				if (ch[i] == ',')
					proverka_tochka++;
			if (proverka_tochka >= 2) {
				proverka = true;
			}
			if (proverka_tochka <= 1)
				for (int i = 0; i < strlen(ch); i++)
					if (ch[i] != '0' && ch[i] != '1' && ch[i] != '2' && ch[i] != '3' && ch[i] != '4' && ch[i] != '5' && ch[i] != '6' && ch[i] != '7' && ch[i] != '8' && ch[i] != '9' && ch[i] != ',') {
						proverka = true;
					}
		}
		cin.clear();
		if (proverka == true)
			printf("�������� ����!\n������� ��� ���: ");
		if (proverka == false)
			pr = true;
	}
	return atof(ch);
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