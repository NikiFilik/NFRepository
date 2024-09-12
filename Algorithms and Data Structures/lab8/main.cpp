#include <iostream>
#include <vector>

void radixSort(int n, int arr[]) {
	int mx = -2147483647 - 1;
	for (int i = 0; i < n; i++) {
		mx = std::max(mx, arr[i]);
	}
	int maxNumberLength = 0;
	while (mx > 0) {
		maxNumberLength++;
		mx /= 10;
	}

	for (int i = 0; i < maxNumberLength; i++) {
		std::vector<int> digits[10];
		for (int j = 0; j < n; j++) {
			int digit = (arr[j] % int(std::pow(10, i + 1))) / std::pow(10, i);
			digits[digit].push_back(arr[j]);
		}
		int index = 0;
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < digits[j].size(); k++) {
				arr[index] = digits[j][k];
				index++;
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

	radixSort(n, arr);

	std::cout << "ќтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}