#pragma once 
#define HASHDEL (void*) -1


struct HashTable {
	void** Data;
	int size,
		current;

	int (*GetKey)(void*);
	void UniversalInsert(void*, int);
	void ModulInsert(void*);
	void MultiplicativeInsert(void*);
	void* UniversalSearch(int, int);
	void* ModulSearch(int);
	void* MultiplicativeSearch(int);
	void UniversalDelete(int, int);
	void ModulDelete(int);
	void MultiplicativeDelete(int);
	void Scan(void(*f)(void*));
	int UniversalSearchPos(int, int);
	int ModulSearchPos(int);
	int MultiplicativeSearchPos(int);

	HashTable(int, int(*)(void*));
};

static void* DEL = (void*)HASHDEL;