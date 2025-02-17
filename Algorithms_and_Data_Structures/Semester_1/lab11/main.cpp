#include <iostream>

void quickSort(int arr[], int l, int r) {
	if (r - l >= 1) {
		int pivot = arr[l];
		int smallerInd = l - 1;
		int biggerInd = r + 1;

		for (int i = l; i < biggerInd; i++) {
			while (i > smallerInd && i < biggerInd && arr[i] != pivot) {
				if (arr[i] < pivot) {
					smallerInd++;
					std::swap(arr[i], arr[smallerInd]);
				}
				if (arr[i] > pivot) {
					biggerInd--;
					std::swap(arr[i], arr[biggerInd]);
				}
			}
		}

		quickSort(arr, l, smallerInd);
		quickSort(arr, biggerInd, r);
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

	quickSort(arr, 0, n - 1);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}