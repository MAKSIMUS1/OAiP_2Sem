#pragma once
#include<fstream>
//�������� ���������� ������� � ����������� ��� ������
struct tNode {
	int data;
	tNode* left, * right;
};

void show(tNode*, int);
tNode* input(tNode*, int);
tNode* del(tNode*, int);
void tClear(tNode*);
void onlyLeft(tNode*, int&);
void leaves(tNode*, int&);

int Correct_Input_Integer();