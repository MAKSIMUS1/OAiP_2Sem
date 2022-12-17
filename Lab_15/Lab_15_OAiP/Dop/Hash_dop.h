#pragma once
#include<iostream>
#define SIZE 26

class Words {
public:
	std::string word;
	Words* next;

	Words() {
		this->next = NULL;
	}
	Words(std::string word) {
		this->word = word;
		this->next = NULL;
	}
};

class HashTable {
private:
	Words* table[SIZE];

public:
	HashTable();
	void push(std::string word);
	void print();
	void search(std::string word);
};