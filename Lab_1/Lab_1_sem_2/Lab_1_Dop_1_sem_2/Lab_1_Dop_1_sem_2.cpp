//Семестр 2 Лаб 1 Вариант 10 задание 4

#include <iostream>
using namespace std;
float f1(float);
float f2(float);
float integ(float(*) (float), float, float, float);
int Correct_Input_Integer();
void first() {
	float z;
	float a, b, e = 0.001;
	a = Correct_Input_Integer();
	b = Correct_Input_Integer();
	z = integ(f1, a, b, e);
	cout << "Integral 1 =" << z << endl << endl;
}
void second() {
	float z;
	float a, b, e = 0.001;
	a = Correct_Input_Integer();
	b = Correct_Input_Integer();
	z = integ(f2, a, b, e);
	cout << "Integral 2 =" << z / 2 << endl << endl;
}
float f1(float x) {
	return(sin(x) + pow(x, 3));
}
float f2(float x) {
	return(0.4 + pow(x, 3));
}

float integ(float(*f) (float), float a, float b, float n) {
	float x;
	while (abs(a - b) > (2 * n))
	{
		x = (a + b) / 2;
		if (f(a) * f(x) <= 0) b = x;
		else a = x;
	}
	return x;
}
int main() {
	first();
	second();
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