//Написать функцию kvadr с переменным числом параметров, которая определяет количество чисел, являющихся точными квадратами (2, 4, 9, 16,…) типа int. 
#include <iostream>
using namespace std;
int kvadr(int n, ...)
{
	int* p = &n;
	int kol = 0;
	p++;
	for (int i = 0; i < n; i++, p++)
	{
		if ((double)sqrt(*(p)) == (int)sqrt(*(p)))
		{
			kol++;
		}
	}
	return kol;
}

int main()
{
	printf("Kolichestvo = %d\n", kvadr(5, 2, 4, 9, 16, 0));
	return 0;
}
