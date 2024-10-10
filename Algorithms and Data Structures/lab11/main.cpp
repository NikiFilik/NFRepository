#include <iostream>

void quickSort(int arr[], int l, int r) {
	if (r - l >= 1) {
		int pivot = arr[l];
		int smallers = l;
		int biggers = r;
		for (int i = l; i < r; i++) {
			if (arr[i] < pivot) {
				std::swap(arr[i], arr[smallers]);
				smallers++;
			}
			if (arr[i] > pivot) {
				std::swap(arr[i], arr[biggers]);
				biggers--;
			}
		}
		quickSort(arr, l, smallers);
		quickSort(arr, biggers, r);
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