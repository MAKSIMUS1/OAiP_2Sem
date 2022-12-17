//	Ввести с клавиатуры строку символов, состоящую из групп цифр и нулей, и записать ее в файл. 
//	Прочитать из файла данные и вывести самую короткую группу
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	char str[200], str1[200];
	int letter = 0, pr = 0, max = 0;

	ofstream ofile("a.txt");
	if (ofile.fail())  //проверка открытия файла
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	bool prof = false;
	cout << "Введите строку:";
	do {
		prof = false;
		cin.ignore(cin.rdbuf()->in_avail());
		gets_s(str1);
		for (int k = 0; k < strlen(str1); k++)
			if ((str1[k] < '0' || str1[k] > '9') && (str1[k] != ' '))
				prof = true;
		if (str1[0] == '\0')
			prof = true;
		if (prof == true)
			printf("Неккоретный ввод, или цифры.\nВведите ещё раз: ");
	} while (prof == true);
	ofile << str1;
	ofile.close();
	ifstream ifile("a.txt");
	if (ifile.fail())  //проверка открытия файла
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	ifile.getline(str, 200);
	ifile.close();
	//Нахождение самого минимального
	int min = 1000;
	for (char* p = strtok(str, " "); p; p = strtok(NULL, " ")) {
		if (strlen(p) < min) {
			min = strlen(p);
			strcpy(str, p);
		}
	}
	cout << "\nСамое короткая группа цифр и нулей: " << str << endl;
}