#include <iostream>

int main() {
	setlocale(LC_ALL, "Russian");


	int numOfDenominations;
	std::cout << "¬ведите количество различных номиналов монет:\n";
	std::cin >> numOfDenominations;


	int* denomination = new int[numOfDenominations + 1];
	std::cout << "¬ведите номиналы монет:\n";
	for (int i = 1; i <= numOfDenominations; i++) {
		std::cin >> denomination[i];
	}


	int sum;
	std::cout << "¬ведите сумму:\n";
	std::cin >> sum;


	int** numOfCombs = new int*[numOfDenominations + 1];
	for (int i = 0; i <= numOfDenominations; i++) {
		numOfCombs[i] = new int[sum + 1]();
	}
	for (int i = 0; i <= numOfDenominations; i++) {
		numOfCombs[i][0] = 1;
	}


	for (int i = 1; i <= numOfDenominations; i++) {
		for (int j = 1; j <= sum; j++) {
			if (j - denomination[i] >= 0) {
				numOfCombs[i][j] = numOfCombs[i - 1][j] + numOfCombs[i][j - denomination[i]];
			}
			else {
				numOfCombs[i][j] = numOfCombs[i - 1][j];
			}
		}
	}

	/*
	for (int i = 0; i <= numOfDenominations; i++) {
		for (int j = 0; j <= sum; j++) {
			std::cout << numOfCombs[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/

	std::cout << "„исло способов выдать сдачу: " << numOfCombs[numOfDenominations][sum];


	for (int i = 0; i <= numOfDenominations; i++) {
		delete[] numOfCombs[i];
	}
	delete[] numOfCombs;

	delete[] denomination;
	return 0;
}