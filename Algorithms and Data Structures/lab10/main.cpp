#include <iostream>
#include <vector>

void mergeSort(int n, int arr[]) {
    if (n > 1) {
        int leftSize = n / 2;
        int rightSize = n - leftSize;

        mergeSort(leftSize, &arr[0]);
        mergeSort(rightSize, &arr[leftSize]);

        int lInd = 0, rInd = leftSize, ind = 0;
        int* tmpArr = new int[n];

        while (lInd < leftSize || rInd < n) {
            if (arr[lInd] < arr[rInd]) {
                tmpArr[ind] = arr[lInd];
                ind++;
                lInd++;
            }
            else {
                tmpArr[ind] = arr[rInd];
                ind++;
                rInd++;
            }

            if (lInd == leftSize) {
                for (; rInd < n; rInd++) {
                    tmpArr[ind] = arr[rInd];
                    ind++;
                }
                break;
            }
            if (rInd == n) {
                for (; lInd < leftSize; lInd++) {
                    tmpArr[ind] = arr[lInd];
                    ind++;
                }
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = tmpArr[i];
        }

        delete[] tmpArr;
    }
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n;

	std::cout << "¬ведите количество элементов массива:\n";
	std::cin >> n;

	int *arr = new int[n];

	std::cout << "¬ведите элементы массива:\n";
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	mergeSort(n, arr);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}