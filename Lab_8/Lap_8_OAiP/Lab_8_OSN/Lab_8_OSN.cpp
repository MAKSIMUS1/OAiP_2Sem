//Создать очередь с вещественными числами, и заполнить ее с клавиатуры. 
//Выполнить циклический сдвиг элементов в очереди так, чтобы в ее начале был расположен наибольший элемент.
#include"Header2.h"
#include<iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int choice, SIZE;
	cout << "Введите размер очереди: ";

	do {
		SIZE = Correct_Input_Integer();
		if (SIZE <= 0)
			printf("Нужно больше 0.\nВведите ещё раз: ");
	} while (SIZE <= 0);
	Queue myQ(SIZE);

	cout << "Введите" << endl;
	cout << "1 - для добавления элемента" << endl;
	cout << "2 - для извлечения элемента" << endl;
	cout << "3 - для вывода очереди" << endl;
	cout << "4 - для удаления очереди" << endl;
	cout << "5 - для определения размера очереди" << endl;
	cout << "6 - циклический сдвиг элементов в очереди так, чтобы в ее начале был расположен наибольший элемент" << endl;
	cout << "9 - для выхода" << endl;

	do {
		cout << "Ожидаю указаний: ";
		choice = Correct_Input_Integer();

		switch (choice) {
		case 1: {
			float x;
			cout << "Введите число: ";
			x = Correct_Input_Float();
			myQ.insert(x);
			break;
		}
		case 2: {
			cout << "Извлеченный элемент: " << myQ.remove() << endl;
			break;
		}
		case 3: {
			myQ.display();
			break;
		}
		case 4: {
			myQ.rear = 0;
			break;
		}
		case 5: {
			cout << "Текущий размер очереди: " << myQ.size() << endl;
			break;
		}
		case 6: {
			float max = myQ.findMax();
			if (max) myQ.cycle(max);
			break;
		}
		case 9: return 0;
			break;
		default:   cout << "Неправильный выбор" << endl;
			cin.clear();
			break;
		}
	} while (choice);
}