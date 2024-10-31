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
		quickSort(arr, 0, i - 1);

		if (currentOut == 'A' && !in.eof()) {
			int n = i;
			for (i = 0; i < n; i++) {
				outA << arr[i] << std::endl;
			}
			currentOut = 'B';
		}
		else if (currentOut == 'B' && !in.eof()){
			int n = i;
			for (i = 0; i < n; i++) {
				outB << arr[i] << std::endl;
			}
			currentOut = 'A';
		}
	}
	delete[] arr;
}

void polyphaseMerge(int chunkLen) {
	int size = chunkLen;
	char input1 = 'A';
	char input2 = 'B';
	char currentOutput = 'C';

	while (true /*ÕÇ, ÁÐÎ, ÍÀÄÎ ÄÓÌÀÒÜ*/) {
		std::ifstream in1;
		std::ifstream in2;

		std::ofstream out1;
		std::ofstream out2;
		if (input1 == 'A' && input2 == 'B') {
			in1.open("tempA.txt", std::ios::in);
			in2.open("tempB.txt", std::ios::in);

			out1.open("tempC.txt", std::ios::out);
			out2.open("tempD.txt", std::ios::out);
		}
		if (input1 == 'C' && input2 == 'D') {
			in1.open("tempC.txt", std::ios::in);
			in2.open("tempD.txt", std::ios::in);

			out1.open("tempA.txt", std::ios::out);
			out2.open("tempB.txt", std::ios::out);
		}

		//Äàííûé while, ïîëó÷àåòñÿ, ïåðåëèâàåò èç îäíîé ïàðû ôàéëîâ â äðóãóþ, óâåëè÷èâàÿ ðàçìåð îòðåçî÷êîâ â äâà ðàçà
		while (!in1.eof() && !in2.eof()) {
			//ÑËÈßÍÈÅ ÄÂÓÕ ÎÒÐÅÇÎ×ÊÎÂ ÄËÈÍÛ size

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
		if (input1 == 'A' && input2 == 'B') {
			input1 = 'C';
			input2 = 'D';
			currentOutput = 'A';
		}
		else if(input1 == 'C' && input2 == 'D'){
			input1 = 'A';
			input2 = 'B';
			currentOutput = 'C';
		}
	}
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	generateInputData(100, 0, 100);

	readInputData(25);

	return 0;
}