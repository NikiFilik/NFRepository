#include <iostream>
#include <fstream>

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

void generateInputData(int size, int mn, int mx) {
	std::ofstream out("input.txt", std::ios::out);

	for (int i = 0; i < size; i++) {
		out << rand() % (mx - mn + 1) + mn << std::endl;
	}
}

void readInputData(int chunkLen) {
	std::ifstream in("input.txt", std::ios::in);

	std::ofstream outA("tempA.txt", std::ios::out);
	std::ofstream outB("tempB.txt", std::ios::out);

	while (!in.eof()) {
		int *arr = new int[chunkLen];
		int i = 0;
		while (!in.eof()) {
			if (i < chunkLen) {
				arr[i];
				i++;
			}
		}
	}
	CreateRuns(S)
		S размер создаваемых отрезков
		CurrentFile = A
		while конец входного файла не достигнут do
			read S записей из входного файла
			sort S записей
			if CurrentFile = A then
				CurrentFile = B
			else
				CurrrentFile = A
				end if
				end while
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	generateInputData(10000, 0, 10000);

	return 0;
}