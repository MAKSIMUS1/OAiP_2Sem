#include"Header.h"
#include<iostream>
#include<fstream>
#include <string>
#include<vector>
#include <algorithm>

using namespace std;
//���� �������
void show(tNode* tree, int space) {		//����� ������
	if (tree) {
		show(tree->left, space + 5);
		for (int i = 0; i < space; i++) {
			cout << " ";
		}
		cout << tree->data << endl;
		show(tree->right, space + 5);
	}
}

tNode* input(tNode* tree, int x) {		//���� ��������
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

tNode* del(tNode* tree, int x) {		//�������� ��������
	tNode* Del, * Prev_del, * R, * Prev_r;

	Del = tree;
	Prev_del = NULL;
	while (Del && Del->data != x) {
		Prev_del = Del;
		if (Del->data > x) Del = Del->left;
		else Del = Del->right;
	}

	if (!Del) {
		cout << "������� �� ������!" << endl;
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

	cout << "������ ������� � ������: " << Del->data << endl;
	delete Del;
	return tree;
}

void tClear(tNode* tree) {			//������� ������
	if (tree) {
		tClear(tree->left);
		tClear(tree->right);
		delete tree;
	}
}

void onlyLeft(tNode* tree, int& sum) {
	if (!tree) {
		cout << "��� ����� ������.\n";
		return;
	}
	if (tree->left != NULL) {
		sum++;
		onlyLeft(tree->left, sum);
	}
	if (tree->right != NULL) {
		onlyLeft(tree->right, sum);
	}
}


void leaves(tNode* tree, int& count) {
	if (!tree) {
		cout << "��� ����� ������.\n";
		return;
	}
	if (tree->left != NULL) {
		leaves(tree->left, count);
	}
	if (tree->right != NULL) {
		leaves(tree->right, count);
	}
	if (tree->right == NULL && tree->left == NULL) {
		count++;
	}
}



//���������� ���� integer
int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[20];

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