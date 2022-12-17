//	Скопировать из файла FILE1 в файл FILE2 все строки, которые содержат только одно слово.
//	Найти самое короткое слово в  файле FILE2.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	int proverka = 0;
	string line;
	ifstream ifile("FILE1.txt");
	ofstream ofile("FILE2.txt");
	if (ifile.is_open())
	{
		while (getline(ifile, line))
		{
			for (int i = 0; i < line.length(); i++) {
				if (line[i] == ' ')
					proverka = 1;
			}
			if (proverka == 0) {
				line += '\n';
				ofile << line;
			}
			proverka = 0;
		}
	}
	else {
		printf("\nОшибка открытия файла");
		exit(1);
	}
	ifile.close();
	ofile.close();
	ifstream FILE2("FILE2.txt");
	int arr[50], i = 0;
	if (FILE2.is_open())
	{
		while (getline(FILE2, line))
		{
			arr[i] = line.length();
			i++;
		}
	}
	else {
		printf("\nОшибка открытия файла");
		exit(1);
	}
	FILE2.close();
	int min = 10000, nomer;
	for (int p = 0; p < i; p++) {
		if (arr[p] < min) {
			min = arr[p];
			nomer = p;
		}
	}
	ifstream FILE("FILE2.txt");
	for (int p = 0; p < i; p++) {
		getline(FILE, line);
		if (nomer == p)
			cout << "Самое короткое предложение: " << line << endl;
	}
	FILE.close();
	printf("Данные переписаны.\n");
}