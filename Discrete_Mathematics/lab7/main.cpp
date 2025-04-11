#include <iostream>
#include <set>
#include <cmath>
#include <random>



const int numOfVertices = 20, maxDistance = 1000;

std::random_device rd;   // non-deterministic generator
std::mt19937 gen(rd());  // to seed mersenne twister.
std::uniform_int_distribution<> randomVertex(0, numOfVertices - 1); // distribute results between 0 and numOfVertices - 1 inclusive.
std::uniform_int_distribution<> randomDistance(0, maxDistance - 1);



int** createGraph(int numOfVertices) {
	int** graph = new int* [numOfVertices];
	for (int i = 0; i < numOfVertices; i++) {
		graph[i] = new int [numOfVertices];
		for (int j = 0; j < numOfVertices; j++) {
			graph[i][j] = -1;
		}
	}
	//std::cout << "Graph created!\n";
	return graph;
}



void clearGraph(int** graph, int numOfVertices) {
	for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			graph[i][j] = -1;
		}
	}
	//std::cout << "Graph cleared!\n";
}



void fillGraph(int** graph, int numOfVertices) {
	int edgesAdded = 0;

	while (edgesAdded < numOfVertices * std::sqrt(numOfVertices)) {
		bool added = false;

		while (!added) {
			int u = randomVertex(gen), v = randomVertex(gen);
			int distance = randomDistance(gen);

			if (u != v && graph[u][v] == -1) {
				graph[u][v] = distance;
				graph[v][u] = distance;
				added = true;
				edgesAdded++;
			}
		}
	}
	//std::cout << "Graph filled!\n";
}



void deleteGraph(int** graph, int numOfVertices) {
	for (int i = 0; i < numOfVertices; i++) {
		delete[] graph[i];
	}
	delete graph;
	//std::cout << "Graph deleted!\n";
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
		//std::cout << "Graph was checked!\n";

		//ADDING K6
		for (int i = 0; i < 6; i++) {
			for (int j = i + 1; j < 6; j++) {
				int distance = randomDistance(gen);
				graph[i][j] = distance;
				graph[j][i] = distance;
			}
		}
		
		//ADDING K5,5
		for (int i = numOfVertices - 10; i < numOfVertices; i++) {
			for (int j = numOfVertices - 10; j < numOfVertices; j++) {
				graph[i][j] = -1;
			}
		}

		for (int i = numOfVertices - 10; i < numOfVertices - 5; i++) {
			for (int j = numOfVertices - 5; j < numOfVertices; j++) {
				int distance = randomDistance(gen);
				graph[i][j] = distance;
				graph[j][i] = distance;
			}
		}
	}
	//std::cout << "Good graph created!\n";
	return graph;
}



int** FloydAlgorithm(int** graph, int numOfVertices) {
	int** shortestPath = createGraph(numOfVertices);
	for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			shortestPath[i][j] = graph[i][j];
		}
	}
	
	for (int k = 0; k < numOfVertices; k++) {
		for (int i = 0; i < numOfVertices; i++) {
			for (int j = 0; j < numOfVertices; j++) {
				if (shortestPath[i][j] > shortestPath[i][k] + shortestPath[k][j]) {
					shortestPath[i][j] = shortestPath[i][k] + shortestPath[k][j];
				}
			}
		}
	}

	return shortestPath;
}

int main() {
	int** graph = createGoodGraph(numOfVertices);
	
	/*for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			std::cout << graph[i][j] << "\t";
		}
		std::cout << "\n";
	}*/

	int** shortestPath = FloydAlgorithm(graph, numOfVertices);

	/*for (int i = 0; i < numOfVertices; i++) {
		for (int j = 0; j < numOfVertices; j++) {
			std::cout << graph[i][j] << "\t";
		}
		std::cout << "\n";
	}*/

	deleteGraph(shortestPath, numOfVertices);
	deleteGraph(graph, numOfVertices);
	return 0;
}