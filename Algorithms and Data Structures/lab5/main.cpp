#include <iostream>

void insertionSort(int n, int arr[]) {
	for (int i = 1; i < n; i++) {
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1]) {
			std::swap(arr[j], arr[j - 1]);
			j--;
		}
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

	insertionSort(n, arr);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}