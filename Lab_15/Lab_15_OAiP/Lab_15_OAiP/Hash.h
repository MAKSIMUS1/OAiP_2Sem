#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable {
private:
	static const int HashGroups = 10;
	list<pair<int, string>> table[HashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int, string);
	void insertItem(int, string);
	void removeItem(int, string);
	void searchTable(int, string);
	void showTable();
};