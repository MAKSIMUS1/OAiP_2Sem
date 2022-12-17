#include <iostream>
#include <cmath>
#include <fstream>

const int N = 5;
int mass[N];

using namespace std;
void change(int k) {
	int i, j, t, p;
	for (i = 0; i < N - k; i++) {
		if (k < N - 2)
			change(k + 1);
		else {
			for (p = 0; p < N; p++) cout << " " << mass[p];
			cout << endl;
		}
		t = mass[k];
		for (j = k + 1; j < N; j++) mass[j - 1] = mass[j];
		mass[j - 1] = t;
	}
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int i;
	for (i = 0; i < N; i++)
		mass[i] = i + 2;
	change(0);
	system("pause");
}