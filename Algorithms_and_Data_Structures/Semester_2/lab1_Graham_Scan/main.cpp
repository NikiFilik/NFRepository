#include <iostream>
#include <algorithm>
#include <vector>

class Point2d {
public:
	int x, y;
};

int crossProduct(Point2d a, Point2d b, Point2d c) {
	return (b.x - a.x) * (c.y - b.y) - (b.y - a.y) * (c.x - b.x);
}

bool comparePoints(Point2d origin, Point2d p1, Point2d p2) {
	if (crossProduct(origin, p1, p2) > 0) {
		return true;
	}
	return false;
}

class pointsComparator {
private:
	Point2d origin;
public:
	pointsComparator(Point2d origin) : origin(origin) {

	}
	bool operator () (Point2d p1, Point2d p2) {
		return comparePoints(this->origin, p1, p2);
	}
};

std::vector<Point2d> GrahamScan(std::vector<Point2d> points) {
	for (int i = 1; i < points.size(); i++) {
		if (points[i].x < points[0].x || (points[i].x == points[0].x && points[i].y < points[0].y)) {
			std::swap(points[i], points[0]);
		}
	}

	std::sort(points.begin() + 1, points.end(), pointsComparator(points[0]));
	/*
	std::cout << "Sorted points:\n";
	for (Point2d i : points) {
		std::cout << "(" << i.x << ", " << i.y << ") ";
	}
	std::cout << "\n";
	*/
	std::vector<Point2d> stack{points[0], points[1]};
	for (int i = 2; i < points.size(); i++) {
		while (crossProduct(stack[stack.size() - 2], stack[stack.size() - 1], points[i]) < 0) {
			stack.pop_back();
		}
		stack.push_back(points[i]);
	}

	return stack;
}

int main() {
	int numOfPoints;
	std::cout << "Enter number of points:\n> ";
	std::cin >> numOfPoints;

	std::vector<Point2d> points(numOfPoints);
	std::cout << "Enter coordinates of points:\n> ";
	for (Point2d& i: points) {
		std::cin >> i.x >> i.y;
	}

	std::vector<Point2d> convexHull = GrahamScan(points);

	bool existenceOfConvexHull = false;
	for (int i = 2; i < convexHull.size(); i++) {
		if (crossProduct(convexHull[0], convexHull[1], convexHull[i]) != 0) {
			existenceOfConvexHull = true;
			break;
		}
	}

	if (existenceOfConvexHull == true) {
		auto iter = convexHull.begin() + 2;
		while (iter != convexHull.end()) {
			if (crossProduct(*(iter - 2), *(iter - 1), *iter) == 0) {
				iter = convexHull.erase(iter - 1) + 1;
			}
			else {
				iter++;
			}
		}

		std::cout << "Coordinates of points in convex hull:\n";
		for (Point2d i : convexHull) {
			std::cout << "(" << i.x << ", " << i.y << ") ";
		}
	}
	else {
		std::cout << "Convex hull does not exist\n";
	}
	
	return 0;
}