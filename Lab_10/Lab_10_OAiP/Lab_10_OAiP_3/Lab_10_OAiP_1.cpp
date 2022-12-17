#include<iostream>
using namespace std;

int x = 2;
float sum = 0;

float sumcos(int n) {
	if (1 > n)
		return sum;
	else {
		sum += cos(n * x);
		return sumcos(n - 1);
	}
}
int main() {
	int n;
	cin >> n;
	cout << sumcos(n);
}