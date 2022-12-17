//	Создать текстовый файл F1 не менее, чем из 6 строк, и записать в него информацию. 
//	Скопировать в файл F2 только те строки из F1, которые заканчиваются символом «а». 
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	int m = 1;
	long fsize;
	char pd;
	FILE* F1;
	FILE* F2;

	errno_t err;
	err = fopen_s(&F1, "F1.txt", "r");
	if (err != 0) {
		perror("Ошибка открытия F1.txt");
		return;
	}
	err = fopen_s(&F2, "F2.txt", "w");
	if (err != 0) {
		perror("Невозможно создать файл F2\n");
		return;
	}

	fseek(F1, 0L, SEEK_END);
	fsize = ftell(F1);
	fseek(F1, 0L, SEEK_SET);

	for (int k = 1; k <= fsize; k++)
	{
		fread((void*)&pd, sizeof(char), 1, F1);
		m++;
		if (pd == 'a') {
			fread((void*)&pd, sizeof(char), 1, F1);
			m++;
			k++;
			if (pd == '.') {
				long pos1 = k - m + 2;
				m -= 2;
				fseek(F1, pos1, SEEK_SET);
				for (int i = 0; i < m ; i++)
				{
					fread((void*)&pd, sizeof(char), 1, F1);
					fprintf(F2, "%c", pd);
				}
				fprintf(F2, "%c", ' ');
				fseek(F1, k, SEEK_SET);
			}
		}
		else
			if (pd == '.')
				m = 1;
	}

	printf("Данные записаны в файл F2.txt\n");
	fclose(F1);
	fclose(F2);
}