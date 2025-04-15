#include <iostream>
#include <vector>
#include <set>
#include <ctime>

void generatePermutations(std::vector<int>& nums, int start, std::vector<std::vector<int>>& permutations) {
	if (start == nums.size() - 1) {
		std::vector<int> permutation;
		for (int num : nums) {
			permutation.push_back(num);
		}
		permutations.push_back(permutation);
	}
	else {
		for (int i = start; i < nums.size(); i++) {
			std::swap(nums[start], nums[i]);
			generatePermutations(nums, start + 1, permutations);
			std::swap(nums[start], nums[i]);
		}
	}
}

int main() {
	std::srand(std::time(0));

	int numOfVertices;

	std::cout << "Input number of vertices in graph: ";
	std::cin >> numOfVertices;

	std::vector<std::vector<int>> graph(numOfVertices, std::vector<int>(numOfVertices));



	//GRAPH GENERATION
	bool isConnected = false;
	while (!isConnected) {
		for (int i = 0; i < numOfVertices; i++) {
			for (int j = i + 1; j < numOfVertices; j++) {
				int probability = 2;
				int edge = rand() % probability == 0 ? 1 : 0;
				graph[i][j] = edge;
				graph[j][i] = edge;
			}
		}

		//CHECKING GRAPH CONNECTIVITY
		std::set<int> needToCheck{0}, checked{};

		while (needToCheck.size() > 0) {
			int current = *(needToCheck.begin());
			needToCheck.erase(current);
			checked.insert(current);

			for (int i = 0; i < numOfVertices; i++) {
				if (graph[current][i] != 0 && needToCheck.count(i) == 0 && checked.count(i) == 0) {
					needToCheck.insert(i);
				}
			}
		}

		if (checked.size() == numOfVertices) {
			isConnected = true;
		}
	}

	std::cout << "\n\n\nGraph:\n";
	for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			std::cout << graph[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n\n";



	//PERMUTATIONS GENERATION
	std::vector<int> nums;
	for (int i = 0; i < numOfVertices; i++) {
		nums.push_back(i);
	}

	std::vector<std::vector<int>> permutations;
	generatePermutations(nums, 0, permutations);

	/*std::cout << "Permutations:\n";
	for (int i = 0; i < permutations.size(); i++) {
		for (int j = 0; j < numOfVertices; j++) {
			std::cout << permutations[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n\n";*/



	//FINDING BEST COLORING
	std::vector<int> bestColoring(numOfVertices);
	int minNumColors = numOfVertices;

	for (int loop = 0; loop < permutations.size(); loop++) {
		std::vector<std::vector<int>> newGraph(numOfVertices, std::vector<int>(numOfVertices));

		for (int i = 0; i < numOfVertices; i++) {
			for (int j = 0; j < numOfVertices; j++) {
				newGraph[permutations[loop][i]][permutations[loop][j]] = graph[i][j];
			}
		}
		
		/*std::cout << "New graph:\n";
		for (int i = 0; i < numOfVertices; i++) {
			for (int j = 0; j < numOfVertices; j++) {
				std::cout << newGraph[i][j] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n\n\n";*/

		//GREEDY ALGORITHM
		std::vector<int> coloring(numOfVertices);
		for (int i = 0; i < numOfVertices; i++) {
			std::set<int> alreadyUsedColors;
			for (int j = 0; j < i; j++) {
				if (newGraph[i][j] == 1) {
					alreadyUsedColors.insert(coloring[j]);
				}
			}
			for (int j = 0; j < numOfVertices; j++) {
				if (std::find(alreadyUsedColors.begin(), alreadyUsedColors.end(), j) == alreadyUsedColors.end()) {
					coloring[i] = j;
					break;
				}
			}
		}
		std::set<int> usedColors;
		for (int i = 0; i < numOfVertices; i++) {
			usedColors.insert(coloring[i]);
		}
		if (usedColors.size() < minNumColors) {
			minNumColors = usedColors.size();
			for (int i = 0; i < numOfVertices; i++) {
				bestColoring[i] = coloring[permutations[loop][i]]; //POSSIBLE PIPA
			}
		}
	}

	std::cout << "Minimum number of colors: " << minNumColors << "\n";
	for (int i = 0; i < numOfVertices; i++) {
		std::cout << bestColoring[i] << "\t";
	}
	return 0;
}