//	Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл.
//	Прочитать из файла данные и вывести все слова, которые содержат букву «х».

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
			if ((str1[k] < 'A' || str1[k] > 'Z') &&
				(str1[k] < 'a' || str1[k] > 'z') &&
				(str1[k] < 'А' || str1[k] > 'я') &&
				(str1[k] != ' '))
				prof = true;
		if (str1[0] == '\0')
			prof = true;
		if (prof == true)
			printf("Неккоретный ввод, можно вводить только буквы.\nВведите ещё раз: ");
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
	//Нахождение слов с "x"
	for (char* p = strtok(str, " "); p; p = strtok(NULL, " ")) {
		char* pr = strchr(p, 'x');
		if (pr != NULL)
			cout << "Вот такое предложение: " << p << endl;
	}
}