//	Компоненты файла fileA – целые отличные от нуля числа, причем положительных чисел столько же, сколько отрицательных.
//	Получить файл fileB, в котором не было бы двух соседних чисел с одинаковым знаком(сохранить порядок следования чисел).
//	fileA: 1 36 -87 -23 68 1256 -98 12 55 -8 -700 -111
//	fileB: 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");

	char str[100], chislo[10];
	int arr[50], pr = 1, k = 0, j = 0, index[2];
	long fsize;
	FILE* fileA;
	FILE* fileB;

	errno_t err;
	err = fopen_s(&fileA, "fileA.txt", "r");
	if (err != 0) {
		perror("Ошибка открытия fileA.txt");
		return;
	}
	err = fopen_s(&fileB, "fileB.txt", "w");
	if (err != 0) {
		perror("Невозможно создать файл\n");
		return;
	}


	fseek(fileA, 0L, SEEK_END);//определение размера содердимого файла
	fsize = ftell(fileA);
	fseek(fileA, 0L, SEEK_SET);
	fgets(str, 100, fileA);//Считывание чисел из файла fileA в строку str

	for (int i = 0; i <= strlen(str); i++) {
		if (str[i] != ' ') {
			chislo[k] = str[i];
			k++;
		}
		else {
			arr[j] = atoi(chislo);
			for (int g = 0; g < 10; g++)
				chislo[g] = '\n';
			k = 0;
			j++;
		}
	}
	arr[j] = atoi(chislo);
	for (int i = 0; i < j; i++) {
		if (arr[i] > 0 && arr[i + 2] > 0) {
			fprintf(fileB, "%d, ", arr[i + 1]);
			i += 2;
		}
		else
			if (arr[i] < 0 && arr[i + 2] < 0) {
				fprintf(fileB, "%d, ", arr[i + 1]);
				i += 2;
			}
			else
				fprintf(fileB, "%d, ", arr[i]);
	}

	printf("Данные записаны в файл fileB.txt\n");
	fclose(fileA);
	fclose(fileB);
}