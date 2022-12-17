#pragma once
struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);         //прототип
int pop(Stack* myStk);           //прототип
void push(int x, Stack* myStk);  //прототип
void clear(Stack* myStk);
void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2);
void show_stacks(Stack* myStk1, Stack* myStk2);
void toFile(Stack* myStk);
int fromFile(Stack* myStk);

int Correct_Input_Integer();