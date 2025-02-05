#include <iostream>
#include <algorithm>
#include <vector>

class Object{
public:
	int weight, value;
};

int main() {
	setlocale(LC_ALL, "Russian");
	
	
	int capacity;
	std::cout << "Введите грузоподъемность рюкзака:\n";
	std::cin >> capacity;


	int numOfObjects;
	std::cout << "Введите количество предметов:\n";
	std::cin >> numOfObjects;


	Object* objects = new Object[numOfObjects + 1]();
	std::cout << "Введите пары чисел вес и ценность каждого предмета:\n";
	for (int i = 1; i <= numOfObjects; i++) {
		std::cin >> objects[i].weight >> objects[i].value;
	}


	int** maxValue = new int*[numOfObjects + 1];
	for (int i = 0; i <= numOfObjects; i++) {
		maxValue[i] = new int[capacity + 1]();
	}
	
	
	for (int i = 1; i <= numOfObjects; i++) {
		for (int j = 0; j <= capacity; j++) {
			if(j - objects[i].weight >= 0) {
				maxValue[i][j] = std::max(maxValue[i - 1][j], maxValue[i - 1][j - objects[i].weight] + objects[i].value);
			}
			else {
				maxValue[i][j] = maxValue[i - 1][j];
			}
		}
	}
	
	/*
	for (int i = 0; i <= numOfObjects; i++) {
		for (int j = 0; j <= capacity; j++) {
			std::cout << maxValue[i][j] << " ";
		}
		std::cout << "\n";
	}
	*/

	std::cout << "Максимальная ценность предметов которые можно уместить в рюкзак: " << maxValue[numOfObjects][capacity] << "\n";
	
	
	std::vector<int> chosenObjects;
	int i = numOfObjects, j = capacity;
	while(i > 0) {
		if(j - objects[i].weight >= 0) {
			if(maxValue[i - 1][j] >= maxValue[i - 1][j - objects[i].weight] + objects[i].value) {
				i--;
			}
			else {
				chosenObjects.push_back(i);
				i--;
				j -= objects[i].weight;
				
			}
		}
		else {
			i--;
		}
	}
	
	
	std::cout << "Номера выбранных предметов: ";
	std::sort(chosenObjects.begin(), chosenObjects.end());
	for(int i = 0; i < chosenObjects.size(); i++){
		std::cout << chosenObjects[i] << " ";
	}
	

	for (int i = 0; i <= numOfObjects; i++) {
		delete[] maxValue[i];
	}
	delete[] maxValue;
	delete[] objects;
	return 0;
}
