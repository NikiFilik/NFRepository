#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int hashFunction(std::string str) {
	int hash = 0;
	for (int i = 0; i < str.size(); i++) {
		hash += str[i];
	}
	return hash;
}

std::vector<std::string>* createHashTable(std::ifstream &in, int tableSize) {
	std::vector<std::string> *hashTable = new std::vector<std::string>[tableSize];

	for (int i = 0; i < tableSize; i++) {
		hashTable[i].clear();
	}

	while (!in.eof()) {
		std::string word;
		in >> word;
		int hash = hashFunction(word);
		int index = hash % tableSize;
		hashTable[index].push_back(word);
	}

	return hashTable;
}

int main() {
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	
	int hashTableSize = 20;
	std::vector<std::string>* hashTable = createHashTable(in, hashTableSize);

	for (int i = 0; i < hashTableSize; i++) {
		out << i << ": ";
		for (int j = 0; j < hashTable[i].size(); j++) {
			out << "\"" << hashTable[i][j] << "\"" << " ";
		}
		out << std::endl;	
	}

	delete[] hashTable;

	return 0;
}