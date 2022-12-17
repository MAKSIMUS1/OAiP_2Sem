//	Ввести с клавиатуры строку символов, состоящую из цифр и слов, разделенных пробелами, и записать ее в файл. 
//	Прочитать из файла данные, подсчитать количество символов в самом длинном слове и вывести его.

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
		gets_s(str);
		for (int k = 0; k < strlen(str); k++)
			if ((str[k] < 'A' || str[k] > 'Z') &&
				(str[k] < 'a' || str[k] > 'z') &&
				(str[k] < 'А' || str[k] > 'я') &&
				(str[k] < '0' || str[k] > '9') &&
				(str[k] != ' '))
				prof = true;
		if (str[0] == '\0')
			prof = true;
		if (prof == true)
			printf("Неккоретный ввод, можно вводить только буквы или цифры.\nВведите ещё раз: ");
	} while (prof == true);
	ofile << str;
	ofile.close();
	ifstream ifile("a.txt");
	if (ifile.fail())  //проверка открытия файла
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}

	ifile.getline(str1, 200);
	ifile.close();
	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] != ' ')
		{
			letter++;
		}
		if (str1[i] == ' ')
		{
			if (letter > max)
			{
				max = letter;
				pr = i;
			}
			letter = 0;
		}
		if (i == strlen(str1) - 1)
		{
			if (letter > max)
			{
				max = letter;
				pr = i + 1;
			}
			letter = 0;
		}
	}
	for (int j = pr - max; j < pr; j++)
	{
		cout << str1[j];
	}
	cout << "\nКоличество символов = " << max;
}