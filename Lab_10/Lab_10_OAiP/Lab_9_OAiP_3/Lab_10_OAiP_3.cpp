#include<iostream>
using namespace std;
float koren(int y, int i) {
	if (i != y)
		return sqrt(1 + (y + i) * koren(y, i + 1));
	else
		return sqrt(1 + (y + i));
}
int main() {
	int n;
	cin >> n;
	cout << koren(n, 1);
}