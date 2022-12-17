#include <iostream>
#include <ctime>
using namespace std;

void show(int arr[], int N) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
}

void countSort(int in[], int out[], int N)
{
	int i, j, count;
	for (i = 0; i < N; ++i)
	{
		for (count = 0, j = 0; j < N; ++j)
			if (in[j] < in[i] || (in[j] == in[i] && i < j))
				count++;
		out[count] = in[i];
	}
}

int getHoarBorder(int A[], int sm, int em)
{
	int i = sm - 1, j = em + 1;
	int brd = A[sm];
	int buf;
	while (i < j)
	{
		/*while (A[--j] < brd);		//по убыванию
		while (A[++i] > brd);*/
		while (A[--j] > brd);		//по возрастанию
		while (A[++i] < brd);
		if (i < j)
		{
			buf = A[j];
			A[j] = A[i];
			A[i] = buf;
		};
	}
	return j;
}
int* HoarSort(int A[], int sm, int em)
{
	if (sm < em)
	{
		int hb = getHoarBorder(A, sm, em);
		HoarSort(A, sm, hb);
		HoarSort(A, hb + 1, em);
	}
	return A;
};

void heapify(int A[], int pos, int n)
{
	int t, tm;
	while (2 * pos + 1 < n)
	{
		t = 2 * pos + 1;
		if (2 * pos + 2 < n && A[2 * pos + 2] >= A[t])
			t = 2 * pos + 2;
		if (A[pos] < A[t])
		{
			tm = A[pos];
			A[pos] = A[t];
			A[t] = tm;
			pos = t;
		}
		else break;
	}
}
void PyramidSort(int A[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		heapify(A, i, n);
	while (n > 0)
	{
		int tm = A[0];
		A[0] = A[n - 1];
		A[n - 1] = tm;
		n--;
		heapify(A, 0, n);
	}
}

void insOrd(int m[], int sm, int em, int e)
{ // m[] - массив чисел; sm - индекс 1-ого элемента левой части; cm - индекс
  //последн. элемента левой части; em - индекс последн. элемента правой части
	int buf;
	int i = sm;
	while (i <= em && m[i] < e)
	{
		if (i - 1 >= sm)
			m[i - 1] = m[i];
		i++;
	}  m[i - 1] = e;
}
int* Merge(int m[], int sm, int cm, int em)
{
	for (int i = 0; i <= sm; i++)
	{
		if (m[i] > m[cm + 1])
		{
			int buf = m[i];
			m[i] = m[cm + 1];
			insOrd(m, cm + 1, em, buf);
		}
	}
	return m;
}
int* MergeSort(int m[], int lm, int sm = 0)
{
	if (lm > 1)
	{
		MergeSort(m, lm / 2, sm);
		MergeSort(m, lm - lm / 2, sm + lm / 2);
		Merge(m, sm, sm + lm / 2 - 1, sm + lm - 1);
	};
	return m;
}


int main() {
	setlocale(LC_ALL, "Rus");
	srand((unsigned)time(NULL));
	clock_t t1, t2;
	const int N = 50000;
	int* A = new int[N];
	int* B = new int[N];
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 500;
	}
	for (int n = 10000; n <= N; n += 10000) {
		memcpy(B, A, n * sizeof(int)); // в В копируем содержимое массива А; Nn * sizeof(int) - количество копируемых байт
		t1 = clock();
		HoarSort(B, 0, n - 1);
		// 0 - индекс первого элемента, n-1 - индекс последнего элемента
		t2 = clock();
		cout << "\n________________________HOAR_______________________________" << endl;
		cout << "Количество тактов, занимаемое сортировкой Хоара: " << t2 - t1 << endl;
		cout << "Количество cекунд, занимаемое сортировкой Хоара: " << (t2 - t1) / CLK_TCK << endl; //(t2 - t1) / 1000
		memcpy(B, A, n * sizeof(int));
		t1 = clock();
		PyramidSort(B, n);
		t2 = clock();
		cout << "\n________________________PYRAMID____________________________" << endl;
		cout << "Количество тактов, занимаемое сортировкой пирамидой: " << t2 - t1 << endl;
		cout << "Количество cекунд, занимаемое сортировкой пирамидой: " << (t2 - t1) / CLK_TCK << endl; //(t2 - t1) / 1000
		memcpy(B, A, n * sizeof(int));
		t1 = clock();
		MergeSort(B, n);
		t2 = clock();
		cout << "\n________________________MERGE______________________________" << endl;
		cout << "Количество тактов, занимаемое сортировкой пирамидой: " << t2 - t1 << endl;
		cout << "Количество cекунд, занимаемое сортировкой пирамидой: " << (t2 - t1) / CLK_TCK << endl; //(t2 - t1) / 1000
	}
}