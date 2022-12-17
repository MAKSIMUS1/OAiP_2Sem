//Написать функцию fsum с переменным числом параметров, в которой определяется сумма чисел типа int по формуле: S=a1*a2+a2*a3+a3*a4+ . . . . 130
#include <iostream>
using namespace std;
int fsum(int n, ...)
{
	int* p = &n;
	int S = 0;
	p++;
	for (int i = 0; i < n - 1; i++, p++)
	{
		S += (*(p) * *(p + 1));
	}
	return S;
}

int main()
{
	printf("Summa = %d\n", fsum(5, 2, 4, 6, 7, 8));
	return 0;
}