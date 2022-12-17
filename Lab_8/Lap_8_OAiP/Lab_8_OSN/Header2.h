#pragma once

struct Queue {
	int maxSize;
	float* arr;
	int front;
	int rear;

	Queue(int s) {
		maxSize = s;
		arr = new float[maxSize];
		front = 0;
		rear = 0;
	}

	void insert(float k);
	float remove();
	int size();
	void display();
	float findMax();
	void cycle(float k);
};

float Correct_Input_Float();
int Correct_Input_Integer();