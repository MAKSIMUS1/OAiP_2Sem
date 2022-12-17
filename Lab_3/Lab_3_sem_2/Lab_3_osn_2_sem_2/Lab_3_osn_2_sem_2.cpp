//	Ввести с клавиатуры две строки символов, состоящих из слов, разделенных пробелами, и записать их в файл.
//	Прочитать из файла данные.
//	Найти самое короткое слово в первой строке и самое длинное во второй строке.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	bool prof = false;
	setlocale(LC_ALL, "Russian");
	int letter = 0, pr = 0, max = 0;
	string line_1, line_2;
	printf("Введите первую строку: ");
	do {
		prof = false;
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, line_1);
		for (int k = 0; k < line_1.length(); k++)
			if ((line_1[k] < 'A' || line_1[k] > 'Z') &&
				(line_1[k] < 'a' || line_1[k] > 'z') &&
				(line_1[k] < 'А' || line_1[k] > 'я') &&
				(line_1[k] != ' '))
				prof = true;
		if (line_1[0] == '\0')
			prof = true;
		if (prof == true)
			printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
	} while (prof == true);
	printf("Введите вторую строку: ");
	do {
		prof = false;
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, line_2);
		for (int k = 0; k < line_2.length(); k++)
			if ((line_2[k] < 'A' || line_2[k] > 'Z') &&
				(line_2[k] < 'a' || line_2[k] > 'z') &&
				(line_2[k] < 'А' || line_2[k] > 'я') &&
				(line_2[k] != ' '))
				pr = true;
		if (line_2[0] == '\0')
			prof = true;
		if (prof == true)
			printf("Неккоретный ввод, можно вводить только буквы!\nВведите ещё раз: ");
	} while (prof == true);
	ofstream ofile("file.txt");
	ofile << line_1;
	ofile << '\n';
	ofile << line_2;
	ofile.close();
	ifstream ifile("file.txt");
	char line1[200], line2[200];
	if (ifile.is_open())
	{
		ifile.getline(line1, 200);
		ifile.getline(line2, 200);
	}
	else {
		printf("\nОшибка открытия файла");
		exit(1);
	}
	ifile.close();
	//Нахождение самого длинного
	for (int i = 0; i < strlen(line2); i++)
	{
		if (line2[i] != ' ')
		{
			letter++;
		}
		if (line2[i] == ' ')
		{
			if (letter > max)
			{
				max = letter;
				pr = i;
			}
			letter = 0;
		}
		if (i == strlen(line2) - 1)
		{
			if (letter > max)
			{
				max = letter;
				pr = i + 1;
			}
			letter = 0;
		}
	}
	char str_big[50];
	int i = 0;
	for (int j = pr - max; j < pr; j++, i++)
		str_big[i] = line2[j];
	str_big[i] = '\0';
	printf("%s\n", str_big);
	cout << "Количество символов = " << max;
	//Нахождение самого минимального
	char str[100];
	int min = 1000;
	for (char* p = strtok(line1, " "); p; p = strtok(NULL, " ")) {
		if (strlen(p) < min) {
			min = strlen(p);
			strcpy(str, p);
		}
	}
	cout << "\nСамое короткое слово: " << str << endl;
}
