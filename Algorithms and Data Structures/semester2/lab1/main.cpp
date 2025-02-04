#include <iostream>

class Point {
public:
	int x, y;
};

int main() {
	setlocale(LC_ALL, "Russian");


	int numOfPoints;
	std::cout << "¬ведите количество точек:\n";
	std::cin >> numOfPoints;


	Point* point = new Point[numOfPoints];
	std::cout << "¬ведите координаты точек:\n";
	for (int i = 0; i < numOfPoints; i++) {
		std::cin >> point[i].x >> point[i].y;
	}


	Point p0 = point[0];
	for (int i = 1; i < numOfPoints; i++) {
		if (point[i].x <= p0.x && point[i].y <= p0.y) {
			p0 = point[i];
		}
	}

	Point pi = p0;
	int k = 0;

	do {
		k++;
		for(int i = k; i < )

	} while (pi.x != p0.x || pi.y != p0.y);


	delete[] point;
	return 0;
}