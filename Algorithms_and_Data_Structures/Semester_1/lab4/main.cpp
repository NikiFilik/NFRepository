#include <iostream>

void combSort(int n, int arr[]) {
	double factor = 1.25;
	int step = n - 1;

	while (step >= 1) {
		for (int i = 0; i + step < n; i++) {
			if (arr[i] > arr[i + step]) {
				std::swap(arr[i], arr[i + step]);
			}
		}
		step /= factor;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n;

	std::cout << "������� ���������� ��������� �������:\n";
	std::cin >> n;

	int *arr = new int[n];

	std::cout << "������� �������� �������:\n";
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	combSort(n, arr);

	std::cout << "��������������� ������:\n";
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}