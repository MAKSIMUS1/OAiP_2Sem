#include <iostream>
#include<ctime>
using namespace std;

void copy(int arr1[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr2[i] = arr1[i];
	}
}

void show(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

void BubbleSort_decrease(int arr[], int size)
{
	int i, j, t;
	for (i = 1; i < size; i++) {
		for (j = size - 1; j >= i; j--) {
			if (arr[j - 1] < arr[j]) {
				t = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = t;
			}
		}
	}
}

int getHoarBorder_decrease(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		while (A[--j] < brd);		//по убыванию
		while (A[++i] > brd);
		/*while (A[--j] > brd);		//по возрастанию
		while (A[++i] < brd);*/
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}

int* HoarSort_decrease(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder_decrease(A, sm, em);
		HoarSort_decrease(A, sm, hb);
		HoarSort_decrease(A, hb + 1, em);
	}
	return A;
};


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Вариант 7" << endl;
	srand((unsigned)time(NULL));
	int size, min = 99, j{};
	cout << "Введите размер массива: ";
	cin >> size;
	int* A = new int[size];
	int* B = new int[size];
	int* C = new int[size];
	for (int i = 0; i < size; i++) {
		A[i] = rand() % 20;
		B[i] = rand() % 70;
		if (A[i] == 0)
			A[i] = rand() % 20;
		if (B[i] == 0)
			B[i] = rand() % 70;
		if (i % 2 == 1) C[i] = B[i];
		else C[i] = A[i];
	}

	cout << "__________________________________________________________" << endl;
	cout << "Массив А: "; show(A, size);
	cout << "\nМассив B: "; show(B, size);
	cout << "\nМассив C: "; show(C, size);

	int* bubbleSort = new int[size];
	copy(C, bubbleSort, size);
	int* hoarSort = new int[size];
	copy(C, hoarSort, size);

	BubbleSort_decrease(bubbleSort, size);
	HoarSort_decrease(hoarSort, 0, size - 1);
	// 0 - индекс первого элемента, size-1 - индекс последнего элемента
	cout << "\n__________________________________________________________" << endl;
	cout << "Сортировка пузырьком (по убыванию): "; show(bubbleSort, size);
	cout << "\nСортировка Хоаром (по убыванию): "; show(hoarSort, size);

	system("pause");
}

