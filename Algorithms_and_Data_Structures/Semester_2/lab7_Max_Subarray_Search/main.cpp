#include <iostream>
#include <ctime>

int* dataCreation(int &arrSize) {
    std::cout << "Input size of array\n> ";
    std::cin >> arrSize;

    int* arr = new int[arrSize];

    int option;
    std::cout << "Select option: 0 - Enter array by yourself, 1 - Random array\n> ";
    std::cin >> option;

    if (option == 0) {
        std::cout << "Input array\n> ";
        for (int i = 0; i < arrSize; i++) {
            std::cin >> arr[i];
        }
    }
    else if (option == 1) {
        int mx = 100, mn = -100;
        for (int i = 0; i < arrSize; i++) {
            arr[i] = rand() % (mx - mn + 1) + mn;
        }

        std::cout << "Generated array\n> ";
        for (int i = 0; i < arrSize; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    return arr;
}

int main(){
    srand(time(NULL));

    int arrSize;
    int* arr = dataCreation(arrSize);

    int* partialSum = new int[arrSize + 1];
    partialSum[0] = 0;
    int* minPartialSum = new int[arrSize + 1];
    minPartialSum[0] = 0;
    int* minPartialSumIndex = new int[arrSize + 1];
    minPartialSumIndex[0] = -1;

    for (int i = 0; i < arrSize; i++) {
        partialSum[i + 1] = partialSum[i] + arr[i];
        if (minPartialSum[i] > partialSum[i + 1]) {
        	minPartialSum[i + 1] = partialSum[i + 1];
        	minPartialSumIndex[i + 1] = i;
		}
		else {
			minPartialSum[i + 1] = minPartialSum[i];
        	minPartialSumIndex[i + 1] = minPartialSumIndex[i];
		}
    }
    std::cout << "\nPartialSumArray\n> ";
    for(int i = 0; i <= arrSize; i++){
    	std::cout << partialSum[i] << " ";
	}
	std::cout << "\n";
    std::cout << "minPartialSumArray\n> ";
    for(int i = 0; i <= arrSize; i++){
    	std::cout << minPartialSum[i] << " ";
	}
	std::cout << "\n";
	std::cout << "minPartialSumIndexArray\n> ";
	for(int i = 0; i <= arrSize; i++){
    	std::cout << minPartialSumIndex[i] << " ";
	}
	std::cout << "\n\n";
	
    int maxSum = 0, firstIndex = -1, lastIndex = -1;
    
    for (int i = 1; i <= arrSize; i++) {
    	if (partialSum[i] - minPartialSum[i - 1] >= maxSum) {
    		maxSum = partialSum[i] - minPartialSum[i - 1];
    		firstIndex = minPartialSumIndex[i - 1] + 1;
    		lastIndex = i - 1;
		}
	}
	
	std::cout << "Max sum in array: " << maxSum << "\n";
	std::cout << "Index of the first number in subarray: " << firstIndex << "\n";
	std::cout << "Index of the last number in subarray: " << lastIndex << "\n";
	
    delete[] arr, partialSum, minPartialSum, minPartialSumIndex;

    return 0;
}
