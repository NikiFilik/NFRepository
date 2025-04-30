#include <iostream>
#include <string>

const int SCREEN_WIDTH = 1920, SCREEN_HEIGHT = 1080;

class Point2d {
private:
	int x, y;
public:
	Point2d(int x, int y) {
		setX(x);
		setY(y);
	}

	void setX(int x) {
		if (x < 0 || x >= SCREEN_WIDTH) {
			std::cerr << "ERROR: Invalid x value\n";
			return;
		}
		this->x = x;
	}
	void setY(int y) {
		if (y < 0 || y >= SCREEN_HEIGHT) {
			std::cerr << "ERROR: Invalid y value\n";
			return;
		}
		this->y = y;
	}

	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}

	std::string toString() const {
		return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
	}
};

std::ostream& operator<<(std::ostream& out, const Point2d& p) {
	return out << p.toString();
}





class Vector2d {
private:
	int x, y;
public:
	Vector2d(int x, int y): x(x), y(y) {

	}

	Vector2d(Point2d p): x(p.getX()), y(p.getY()) {

	}

	Vector2d(Point2d p1, Point2d p2) : x(p2.getX() - p1.getX()), y(p2.getY() - p1.getY()) {

	}

	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}

	int getX() const {
		return x;
	}
	int getY() const {
		return y;
	}

	std::string toString() const {
		return "(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ")";
	}

	float abs() const {
		return std::sqrt(x * x + y * y);
	}

	float dotProduct(Vector2d other) const {
		return x * other.getX() + y * other.getY();
	}

	int crossProduct(Vector2d other) const {
		return x * other.getY() - y * other.getX();
	}

	Vector2d operator + (Vector2d other) const {
		return Vector2d(x + other.getX(), y + other.getY());
	}
	Vector2d& operator += (Vector2d other) {
		x += other.getX();
		y += other.getY();
		return *this;
	}

	Vector2d operator - (Vector2d other) const {
		return Vector2d(x - other.getX(), y - other.getY());
	}
	Vector2d& operator -= (Vector2d other) {
		x -= other.getX();
		y -= other.getY();
		return *this;
	}
	Vector2d operator - () const {
		return Vector2d(-x, -y);
	}

	Vector2d& operator *= (int n) {
		x *= n;
		y *= n;
		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, const Vector2d& v) {
	return out << v.toString();
}

Vector2d operator * (int n, Vector2d v) {
	return Vector2d(v.getX() * n, v.getY() * n);
}
Vector2d operator * (Vector2d v, int n) {
	return Vector2d(v.getX() * n, v.getY() * n);
}

int main() {
	Point2d A(3, 4);
	std::cout << A;

	Vector2d V(7, 5);
	std::cout << V;
	return 0;
}