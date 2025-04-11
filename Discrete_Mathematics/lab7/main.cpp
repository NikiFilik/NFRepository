#include <iostream>
#include <set>
#include <cmath>
#include <random>

const int numOfVertices = 37000;

std::random_device rd;   // non-deterministic generator
std::mt19937 gen(rd());  // to seed mersenne twister.
std::uniform_int_distribution<> dist(0, numOfVertices - 1); // distribute results between 1 and 6 inclusive.

int** createGraph(int numOfVertices) {
	int** graph = new int* [numOfVertices];
	for (int i = 0; i < numOfVertices; i++) {
		graph[i] = new int [numOfVertices];
		for (int j = 0; j < numOfVertices; j++) {
			graph[i][j] = -1;
		}
	}
	return graph;
}



void clearGraph(int** graph, int numOfVertices) {
	for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			graph[i][j] = -1;
		}
	}
}



void fillGraph(int** graph, int numOfVertices) {
	int edgesAdded = 0;

	while (edgesAdded < numOfVertices * std::sqrt(numOfVertices)) {
		bool added = false;

		while (!added) {
			int u = dist(gen), v = dist(gen);
			int distance = dist(gen);

			if (u != v && graph[u][v] == -1) {
				graph[u][v] = distance;
				graph[v][u] = distance;
				added = true;
				edgesAdded++;
			}
		}
	}
}



void deleteGraph(int** graph, int numOfVertices) {
	for (int i = 0; i < numOfVertices; i++) {
		delete[] graph[i];
	}
	delete graph;
}



int** createGoodGraph(int numOfVertices) {
	int** graph = createGraph(numOfVertices);

	bool isConnected = false;
	
	while (!isConnected) {
		clearGraph(graph, numOfVertices);
		isConnected = false;

		fillGraph(graph, numOfVertices);

		//CHECKING GRAPH CONNECTIVITY
		std::set<int> needToCheck{0}, checked{};

		while (needToCheck.size() > 0) {
			int current = *(needToCheck.begin());
			needToCheck.erase(current);
			checked.insert(current);

			for (int i = 0; i < numOfVertices; i++) {
				if (graph[current][i] != -1 && needToCheck.count(i) == 0 && checked.count(i) == 0) {
					needToCheck.insert(i);
				}
			}
		}

		if (checked.size() == numOfVertices) {
			isConnected = true;
		}
	}
	return graph;
}

int main() {
	int** graph = createGoodGraph(numOfVertices);
	
	/*for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			std::cout << graph[i][j] << "\t";
		}
		std::cout << "\n";
	}*/

	deleteGraph(graph, numOfVertices);
	return 0;
}