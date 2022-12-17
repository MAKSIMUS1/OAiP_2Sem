#include <iostream>
using namespace std;

struct  Node {
	int x;
	Node* Next;
};

struct List {
	Node* Head, * Tail;
	int size;

	List() :Head(NULL), Tail(NULL), size(0) {};
	void Add(int x);
	bool Del(int k);
	void Show(int size);
	int Count();
};

void main() {
	setlocale(LC_ALL, "RUS");
	int n, k;
	List lst;

	cout << "Введите кол-во элементов в списке: "; cin >> n;
	for (int i = 1; i < n + 1; i++) {
		lst.Add(i);
	}
	cout << "Список:" << endl;
	lst.Show(lst.Count());

	cout << "\nВведите k: "; cin >> k;
	lst.Del(k);
	cout << endl;
	cout << "Выживший: человек под номером " << lst.Head->x;
}

int List::Count() {
	return size;
}

void List::Add(int x) {
	size++;
	Node* temp = new Node;
	temp->Next = Head;
	temp->x = x;

	if (Head != NULL)
	{
		Tail->Next = temp;
		Tail = temp;
	}
	else Head = Tail = temp;
}

bool List::Del(int k) {
	if (Head == NULL) {
		cout << "Список пуст!" << endl;
		return false;
	}
	Node* temp = Tail;
	while (Head != Tail)
	{
		for (int i = 1; i < k; i++) temp = temp->Next;
		Node* buf = temp->Next;
		if (buf == Head) Head = buf->Next;
		if (buf == Tail) Tail = temp;
		temp->Next = buf->Next;
		cout << "Человек под номером " << buf->x << " удален!" << endl;
		delete buf;
	}
	return true;
}

void List::Show(int temp) {
	Node* tempHead = Head;

	temp = size;
	while (temp != 0)
	{
		cout << tempHead->x << " ";
		tempHead = tempHead->Next;
		temp--;
	}
}
