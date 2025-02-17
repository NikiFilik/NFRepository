#include <iostream>

void heapify(int n, int arr[], int i) {
	int largest = i;

	int left = 2 * i + 1, right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest]) {
		largest = left;
	}

	if (right < n && arr[right] > arr[largest]) {
		largest = right;
	}

	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(n, arr, largest);
	}
}

void heapSort(int n, int arr[]) {
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(n, arr, i);
	}

	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);

		heapify(i, arr, 0);
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

	heapSort(n, arr);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}