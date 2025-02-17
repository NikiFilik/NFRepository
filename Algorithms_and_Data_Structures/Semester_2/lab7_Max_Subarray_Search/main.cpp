#include <iostream>

int* dataCreation(int &arrSize) {
    std::cout << "Input size of array\n>";
    std::cin >> arrSize;

    int* arr = new int[arrSize];

    int option;
    std::cout << "Select option: 0 - Enter array by yourself, 1 - Random array\n>";
    std::cin >> option;

    if (option == 0) {
        std::cout << "Input array\n>";
        for (int i = 0; i < arrSize; i++) {
            std::cin >> arr[i];
        }
    }
    else if (option == 1) {
        int mx = 100, mn = -100;
        for (int i = 0; i < arrSize; i++) {
            arr[i] = rand() % (mx - mn + 1) + mn;
        }

        std::cout << "Generated array\n>";
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

    for (int i = 0; i < arrSize; i++) {
        partialSum[i + 1] = partialSum[i] + arr[i];
        minPartialSum[i + 1] = std::min(minPartialSum[i], partialSum[i + 1]);
    }



    int* maxSum = new int[arrSize + 1];
    maxSum[0] = 0;

    int* startIndex = new int[arrSize + 1];
    int* finishIndex = new int[arrSize + 1];
    startIndex[0] = -1; finishIndex[0] = -1;

    for (int i = 0; i < arrSize; i++) {
        maxSum[i + 1] = std::max(maxSum[i], partialSum[i + 1] - minPartialSum[i + 1]);
        if (maxSum[i] > partialSum[i + 1] - minPartialSum[i + 1]) {
            maxSum[i + 1] = maxSum[i];
            startIndex[i + 1] = startIndex[i];
            finishIndex[i + 1] = finishIndex[i];
        }
        else {
            maxSum[i + 1] = partialSum[i + 1] - minPartialSum[i + 1];
        }
    }

    std::cout << maxSum[arrSize];

    delete[] arr, partialSum, minPartialSum;
    delete[] maxSum, startIndex, finishIndex;

    return 0;
}