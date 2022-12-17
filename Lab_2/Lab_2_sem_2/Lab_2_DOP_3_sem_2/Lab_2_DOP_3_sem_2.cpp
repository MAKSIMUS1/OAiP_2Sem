//	Компоненты файла f – целые двухзначные числа.
//	Получить файл g, образованный из f включением только чисел больших некоторого числа, вводимого с клавиатуры.
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "D:\Correct_Input.h"
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");

	char str[100], chislo[10];
	int arr[50], pr = 1, k = 0, j = 0, index[2], number;;
	long fsize;
	FILE* f;
	FILE* g;

	errno_t err;
	err = fopen_s(&f, "f.txt", "r");
	if (err != 0) {
		perror("Ошибка открытия f.txt");
		return;
	}
	err = fopen_s(&g, "g.txt", "w");
	if (err != 0) {
		perror("Невозможно создать файл\n");
		return;
	}


	fseek(f, 0L, SEEK_END);//определение размера содердимого файла
	fsize = ftell(f);
	fseek(f, 0L, SEEK_SET);
	fgets(str, 100, f);//Считывание чисел из файла f в строку str
	printf("Введите число: \n");
	number = Correct_Input_Integer();
	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] != ' ') {
			chislo[k] = str[i];
			k++;
		}
		else {
			arr[j] = atoi(chislo);
			for (int p = 0; p < 10; p++)
				chislo[p] = '\n';
			k = 0;
			j++;
		}
	}
	arr[j] = atoi(chislo);
	for (int i = 0; i <= j; i++)
		if(arr[i] > number)
			fprintf(g, "%d, ", arr[i]);

	printf("Данные записаны в файл g.txt\n");
	fclose(f);
	fclose(g);
}