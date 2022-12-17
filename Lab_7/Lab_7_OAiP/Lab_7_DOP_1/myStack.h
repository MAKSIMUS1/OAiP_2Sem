#pragma once
struct Stack
{
	int data;             //информационный элемент
	Stack* head;		 //вершина стека 
	Stack* next;		 //указатель на следующий элемент
};

void show(Stack* myStk);       
int pop(Stack* myStk);           
void push(int x, Stack* myStk);  
void clear(Stack* myStk);
void create_stacks(Stack* myStk, Stack* myStk1, Stack* myStk2);
void show_stacks(Stack* myStk1, Stack* myStk2);
void toFile(Stack* myStk);
int fromFile(Stack* myStk);

int Correct_Input_Integer();