#include <iostream>
#include <cmath>

using namespace std;
int numsq(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	if (b != 0)
	{
		return floor(a / b) + numsq(b, a % b);
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, m, n, number;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Результат: " << numsq(a, b) << " квадратов." << endl;
	system("pause");
}