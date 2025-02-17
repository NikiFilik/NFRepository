#include <iostream>

void ShellSort(int n, int arr[]) {
	for (int d = n / 2; d > 0; d /= 2) {
		for (int i = d; i < n; i++) {
			int j = i;
			while (j > 0 && arr[j] < arr[j - d]) {
				std::swap(arr[j], arr[j - d]);
				j -= d;
			}
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

	ShellSort(n, arr);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}