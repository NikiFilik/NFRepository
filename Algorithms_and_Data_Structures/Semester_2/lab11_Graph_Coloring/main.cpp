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

	std::cout << "Graph:\n";
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

	std::cout << "Permutations:\n";
	for (int i = 0; i < permutations.size(); i++) {
		for (int j = 0; j < numOfVertices; j++) {
			std::cout << permutations[i][j] << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n\n\n";
	return 0;
}