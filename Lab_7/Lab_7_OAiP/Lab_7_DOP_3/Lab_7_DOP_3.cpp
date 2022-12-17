//Разработать функцию, которая по одному стеку строит два новых: Stack1 из положительных элементов и Stack2 из отрицательных.
#include <iostream>
#include "myStack_3.h"
#include <fstream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
	int choice;
	Stack* myStk = new Stack; //выделение памяти для стека
	Stack* myStk1 = new Stack; //выделение памяти для стека Stack1
	Stack* myStk2 = new Stack; //выделение памяти для стека Stack2
	myStk->head = NULL;       //инициализация первого элемента	
	myStk1->head = NULL;
	myStk2->head = NULL;
	for (;;)
	{
		printf("----------------------------------------------------------\n");
		printf("Выберите команду:\n");
		printf("1 - Добавление элемента в стек\n");
		printf("2 - Извлечение элемента из стека\n");
		printf("3 - Вывод стека\n");
		printf("4 - Очистить стек\n");
		printf("5 - Построение Stack1 из положительных элементов, Stack2 из отрицательных\n");
		printf("6 - Сохранение в файл\n");
		printf("7 - Считать файл\n");
		printf("8 - Вывод Stack1 и Stack2\n");
		printf("9 - Выход\n");
		printf("----------------------------------------------------------\n");
		choice = Correct_Input_Integer();
		switch (choice)
		{
		case 1:
			printf("Введите число: ");
			choice = Correct_Input_Integer();
			push(choice, myStk);
			break;
		case 2:
			choice = pop(myStk);
			if (choice != -1)
				printf("Извлеченный элемент: %d\n", choice);
			break;
		case 3:
			printf("Весь стек:\n");
			show(myStk);
			break;
		case 4:
			clear(myStk);
			break;
		case 5:
			create_stacks(myStk, myStk1, myStk2);
			break;
		case 6:
			toFile(myStk);
			break;
		case 7:
			choice = fromFile(myStk);
			if (choice == -1)
				printf("Файл пуст.\n");
			if (choice == 1)
				printf("\nСтек считан из файла file.txt\n");
			break;
		case 8:
			show_stacks(myStk1, myStk2);
			break;
		case 9:
			return 0;
			break;
		default:
			printf("Неправильный выбор\n");
			break;
		}
	}
	return 0;
}