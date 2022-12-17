#pragma once
struct Stack
{
	int data;             //�������������� �������
	Stack* head;		 //������� ����� 
	Stack* next;		 //��������� �� ��������� �������
};

void show(Stack* myStk);         //��������
int pop(Stack* myStk);           //��������
void push(int x, Stack* myStk);  //��������
void clear(Stack* myStk);
void clear_sp(Stack* myStk);
void toFile(Stack* myStk);
int fromFile(Stack* myStk);

int Correct_Input_Integer();