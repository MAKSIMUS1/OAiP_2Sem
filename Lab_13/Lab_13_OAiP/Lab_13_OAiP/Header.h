#pragma once

int Correct_Input_Integer();

struct AAA
{
	int x;
	void Print();
	int GetPriority();
};

namespace heap
{
	enum CMP { LESS = -1, EQUAL = 0, GREAT = 1 };

	struct Heap
	{
		int Size;
		int MaxSize;
		void** Storage;
		CMP(*Compare)(void*, void*);
		Heap(int maxsize, CMP(*f)(void*, void*))
		{
			Size = 0;
			Storage = new void* [MaxSize = maxsize];
			Compare = f;
		};

		Heap(int maxsize, CMP(*f)(void*, void*), void* x[])
		{
			Size = 0;
			Storage = x;
			MaxSize = maxsize;
			Compare = f;
		};

		int Left(int ix);
		int Right(int ix);
		int Parent(int ix);
		bool isFull()		//ќчередь полна€?
		{
			return (Size >= MaxSize);
		};
		bool isEmpty()		//ќчередь пуста€?
		{
			return (Size <= 0);
		};
		bool isLess(void* x1, void* x2)
		{
			return Compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2)
		{
			return Compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2)	//Ёлементы одинаковые?
		{
			return Compare(x1, x2) == EQUAL;
		};
		void Swap(int i, int j);
		void Heapify(int ix);
		void Insert(void* x);
		void* ExtractMax();
		void DeleteHeap();
		void Scan(int i);
		void* ExtractMin();
		void* ExtractI(int i);
		void Union(Heap&);
	};
	Heap Create(int maxsize, CMP(*f)(void*, void*));
};