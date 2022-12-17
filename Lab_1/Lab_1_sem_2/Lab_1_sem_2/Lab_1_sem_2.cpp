//Семестр 2 Лаб 1 Вариант 11 задание 4


//#include <iostream>
//using namespace std;
//int Correct_Input_Integer();
//float f1(float);
//float f2(float);
//float integ(float(*) (float), float, float, float);
//
//
//void first() {
//	float z;
//	float e = 0.001;
//	int a, b;
//	a = Correct_Input_Integer();
//	b = Correct_Input_Integer();
//	z = integ(f1, a, b, e);
//	cout << "Integral 1 =" << z << endl << endl;
//}
//void second() {
//	float z;
//	float e = 0.001;
//	int a, b;
//	a = Correct_Input_Integer();
//	b = Correct_Input_Integer();
//	z = integ(f2, a, b, e);
//	cout << "Integral 2 =" << z / 2 << endl << endl;
//}
//float f1(float x) {
//	return(exp(x) + 2 * pow(x, 2) - 3);
//}
//float f2(float x) {
//	return(pow(x, 3) + 3);
//}
//float integ(float(*f) (float), float a, float b, float n) {
//	float x;
//	while (abs(a - b) > (2 * n))
//	{
//		x = (a + b) / 2;
//		if (f(a) * f(x) <= 0) b = x;
//		else a = x;
//	}
//	return x;
//}
//int main() {
//	first();
//	second();
//}


//Семестр 2 Лаб 1 Вариант 11 задание 5
//Написать функцию с переменным числом параметров, которая находит минимальное значение матри-цы. С ее помощью найти минимальные значения в n матрицах

#include <iostream>
using namespace std;

int Correct_Input_Integer();

int min(int n, ...)
{
	int min = 200000;
	int* p = &n;
	p++;
	for (int i = 0; i < n; i++)
	{
		if (*(p) < min)
		{
			min = *(p);
		}
		p += 1;
	}
	return min;
}
int main()
{
	srand((unsigned)time(NULL));
	int n;
	printf("vvedite kol-vo matriz n\n");
	n = Correct_Input_Integer();
	int ptr[6];
	int* minimalnie;
	minimalnie = new int[n];
	for (int i = 0; i < n; i++)
	{
		printf("matriza #%d\n", i + 1);
		for (int j = 0; j < 6; j++)
		{
			ptr[j] = rand() * (60 - -(10)) / RAND_MAX + -(10);// генерация от -10 до 60
			printf("element matrizy #%d = %d\n", j + 1, ptr[j]);
		}
		minimalnie[i] = min(6, ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5]);
	}
	for (int i = 0; i < n; i++)
		printf("minimalny element matrizy #%d = %d\n", i + 1, minimalnie[i]);
	int minimaln = 200000;
	for (int i = 0; i < n; i++) {
		if (minimalnie[i] < minimaln)
			minimaln = minimalnie[i];
	}
	printf("samuy minimalnuy element = %d", minimaln);
	delete[] minimalnie;
	return 0;
}

int Correct_Input_Integer() {
	int value, proverka = 0, proverka_2 = 0, proverka_na_minus = 0;
	char ch[50];

	while (proverka != 1) //Если proverka_na_minus = 1, значит первый символ минус. Если proverka_na_minus = 2, значит первый символ число.Если
	{ //Если proverka_2 = 1, значит ввод неверный.
		printf("Input value: ");//Если proverka_2 = 0, значит ввод верный и мы заканчиваем цикл и переводим в int.
		gets_s(ch);
		if (ch[0] == '-')
			proverka_na_minus = 1;
		else
			if (ch[0] >= '0' && ch[0] <= '9')
				proverka_na_minus = 2;
			else
				proverka_2 = 1;
		if (proverka_na_minus == 1)//Если первый символ минус, то тогда идет проверка каждого символа
			for (int i = 1; i < strlen(ch); i++) {
				if (ch[i] < '0' || ch[i] > '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka_2 != 1) {
					proverka_2 = 0;
				}
			}
		if (proverka_na_minus == 2)//Если первый символ число, то тогда проперка всего числа
			for (int i = 0; i < strlen(ch); i++) {
				if (ch[i] < '0' || ch[i] > '9') {
					proverka_2 = 1;
				}
				if (ch[i] >= '0' && ch[i] <= '9' && proverka_2 != 1) {
					proverka_2 = 0;
				}
				if (ch[i] == '\n')
					break;
			}
		cin.clear();
		proverka_na_minus = 0;
		if (proverka_2 == 1)
			printf("Input error\n");
		if (proverka_2 == 0)
			proverka = 1;
		proverka_2 = 0;
	}
	value = atoi(ch);
	printf("Input correct.\nValue = %d\n", value);
	return value;
}