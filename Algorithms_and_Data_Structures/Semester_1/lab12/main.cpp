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

	char currentOut = 'A';
	int* arr = new int[chunkLen];

	while (!in.eof()) {
		int i = 0;

		while (!in.eof() && i < chunkLen) {
			in >> arr[i];
			i++;
		}
		
		if (!in.eof()) {
			quickSort(arr, 0, i - 1);

			if (currentOut == 'A') {
				int n = i;

				for (i = 0; i < n; i++) {
					outA << arr[i] << std::endl;
				}

				currentOut = 'B';
			}
			else if (currentOut == 'B') {
				int n = i;

				for (i = 0; i < n; i++) {
					outB << arr[i] << std::endl;
				}

				currentOut = 'A';
			}
		}
		else {
			quickSort(arr, 0, i - 2);

			if (currentOut == 'A') {
				int n = i - 1;

				for (i = 0; i < n; i++) {
					outA << arr[i] << std::endl;
				}

				currentOut = 'B';
			}
			else if (currentOut == 'B') {
				int n = i - 1;

				for (i = 0; i < n; i++) {
					outB << arr[i] << std::endl;
				}

				currentOut = 'A';
			}
		}
	}
	delete[] arr;
}

void polyphaseMerge(int chunkLen) {
	int size = chunkLen;
	char input1 = 'A';
	char input2 = 'B';
	char currentOutput = 'C';

	int outCnt1 = -1, outCnt2 = -1;

	while (outCnt1 != 0 && outCnt2 != 0) {
		outCnt1 = 0;
		outCnt2 = 0;

		std::ifstream in1;
		std::ifstream in2;

		std::ofstream out1;
		std::ofstream out2;
		if (input1 == 'A') {
			in1.open("tempA.txt", std::ios::in);
			in2.open("tempB.txt", std::ios::in);

			out1.open("tempC.txt", std::ios::out);
			out2.open("tempD.txt", std::ios::out);
		}
		if (input1 == 'C') {
			in1.open("tempC.txt", std::ios::in);
			in2.open("tempD.txt", std::ios::in);

			out1.open("tempA.txt", std::ios::out);
			out2.open("tempB.txt", std::ios::out);
		}

		while (!in1.eof() && !in2.eof()) {
			int alreadyRead1 = 0, alreadyRead2 = 0;
			int value1, value2;
			bool used1 = true, used2 = true;

			while ((alreadyRead1 < size && !in1.eof()) || !used1 || (alreadyRead2 < size && !in2.eof()) || !used2) {
				if (alreadyRead1 < size && !in1.eof() && used1) {
					in1 >> value1;
					if (!in1.eof()) {
						used1 = false;
						alreadyRead1++;
					}
				}
				if (alreadyRead2 < size && !in2.eof() && used2) {
					in2 >> value2;
					if (!in2.eof()) {
						used2 = false;
						alreadyRead2++;
					}
				}

				if (used1 == false && used2 == false) {
					if (value1 <= value2) {
						if (currentOutput == 'A' || currentOutput == 'C') {
							out1 << value1 << std::endl;
							used1 = true;
							outCnt1++;
						}
						else {
							out2 << value1 << std::endl;
							used1 = true;
							outCnt2++;
						}
					}
					else {
						if (currentOutput == 'A' || currentOutput == 'C') {
							out1 << value2 << std::endl;
							used2 = true;
							outCnt1++;
						}
						else {
							out2 << value2 << std::endl;
							used2 = true;
							outCnt2++;
						}
					}
				}
				else if(used1 == false) {
					if (currentOutput == 'A' || currentOutput == 'C') {
						out1 << value1 << std::endl;
						used1 = true;
						outCnt1++;
					}
					else {
						out2 << value1 << std::endl;
						used1 = true;
						outCnt2++;
					}
				}
				else if (used2 == false) {
					if (currentOutput == 'A' || currentOutput == 'C') {
						out1 << value2 << std::endl;
						used2 = true;
						outCnt1++;
					}
					else {
						out2 << value2 << std::endl;
						used2 = true;
						outCnt2++;
					}
				}
			}

			if (currentOutput == 'A') {
				currentOutput = 'B';
			}
			else if (currentOutput == 'B') {
				currentOutput = 'A';
			}
			else if (currentOutput == 'C') {
				currentOutput = 'D';
			}
			else if (currentOutput == 'D') {
				currentOutput = 'C';
			}
		}

		size *= 2;
		if (input1 == 'A') {
			input1 = 'C';
			input2 = 'D';
			currentOutput = 'A';
		}
		else if(input1 == 'C'){
			input1 = 'A';
			input2 = 'B';
			currentOutput = 'C';
		}
	}

	std::ifstream in;
	std::ofstream out("output.txt", std::ios::out);

	if (currentOutput == 'C') {
		in.open("tempA.txt", std::ios::in);
	}
	else {
		in.open("tempC.txt", std::ios::in);
	}

	while (!in.eof()) {
		int value;
		in >> value;
		if (!in.eof()) {
			out << value << std::endl;
		}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int memoryLimit = 25;

	generateInputData(1234, -1000, 1000);

	readInputData(memoryLimit);

	polyphaseMerge(memoryLimit);

	return 0;
}