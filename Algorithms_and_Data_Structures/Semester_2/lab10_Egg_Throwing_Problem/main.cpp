#include <iostream>

int main() {
	int numOfEggs, numOfFloors, numOfAttempts = 1000;
	std::cout << "Enter number of eggs: ";
	std::cin >> numOfEggs;
	std::cout << "Enter number of floors: ";
	std::cin >> numOfFloors;


	long long** maxFloor = new long long*[numOfAttempts + 1];
	for (int i = 0; i <= numOfAttempts; i++) {
		maxFloor[i] = new long long[numOfEggs + 1]();
	}

	for (int i = 0; i <= numOfAttempts; i++) {
		maxFloor[i][0] = 0;
	}
	for (int i = 0; i <= numOfEggs; i++) {
		maxFloor[0][i] = 0;
	}

	int answer = 0;

	for (int i = 1; i <= numOfAttempts; i++) {
		for (int j = 1; j <= numOfEggs; j++) {
			maxFloor[i][j] = maxFloor[i - 1][j - 1] + maxFloor[i - 1][j] + 1;
		}

		if (maxFloor[i][numOfEggs] >= numOfFloors) {
			answer = i;
			break;
		}
	}

	/*
	for (int i = 0; i <= numOfAttempts; i++) {
		for (int j = 0; j <= numOfEggs; j++) {
			std::cout << maxFloor[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/

	std::cout << "Number of attempts: " << answer;

	for (int i = 0; i < numOfAttempts; i++) {
		delete[] maxFloor[i];
	}
	delete[] maxFloor;
	return 0;
}