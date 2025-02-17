#include <iostream>

void selectionSort(int n, int arr[]) {
	for (int i = 0; i < n - 1; i++) {
		int indexOfMin = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[indexOfMin]) {
				indexOfMin = j;
			}
		}

		std::swap(arr[i], arr[indexOfMin]);
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

	selectionSort(n, arr);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}