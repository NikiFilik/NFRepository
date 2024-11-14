#include <iostream>
#include <fstream>
#include <string>

int hashFunction(std::string str) {
	int hash = 0;
	for (int i = 0; i < str.size(); i++) {
		hash += str[i];
	}
	return hash;
}

std::string* createHashTable(std::ifstream &in, int tableSize) {
	std::string *hashTable = new std::string[tableSize];

	while (!in.eof()) {
		std::string word;
		in >> word;
		std::cout << word << std::endl;
		int hash = hashFunction(word);
		int index = hash % tableSize;
		hashTable[index] = word;
	}

	return hashTable;
}

int main() {
	std::ifstream in("input.txt");
	
	std::string* hashTable = createHashTable(in, 20);
	return 0;
}