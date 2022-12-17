//	Компоненты файла fileA –  целые числа, значения которых повторяются.  
//	Получить файл fileB, образованный из fileA числами, которые встречаются в A ровно 2 раза.
//	fileA: 12 3 567 8 36 44 12 529 4 8 10 99 3 2 3 2 3 18 2 
//	fileB: 12 8
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
	if (err != 0){
		perror("Ошибка открытия fileA.txt");
		return;
	}
	err = fopen_s(&fileB, "fileB.txt", "w");
	if (err != 0){
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
	}//Из char в int
	arr[j] = atoi(chislo);
	for (int i = 0; i <= j; i++) {
		for (int k = 0; k <= j; k++) {
			if (i != k && arr[i] == arr[k]) {
				index[0] = i;
				index[1] = k;
				pr++;				
			}
		}
		if (pr == 2) {
			fprintf(fileB, "%d, ", arr[i]);
			for (int g = index[0]; g < 50; g++)
				arr[g] = arr[g + 1];
			for (int g = index[1]; g < 49; g++)
				arr[g] = arr[g + 1];
		}
		pr = 1;
	}

	printf("Данные записаны в файл fileB.txt\n");
	fclose(fileA);
	fclose(fileB);
}