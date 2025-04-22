#include <iostream>
#include <string>
#include <vector>



class Point {
public:
	float x, y;

	Point() : x(0.f), y(0.f) {

	}

	Point(float x, float y) : x(x), y(y) {

	}

	bool operator == (Point other) {
		return (this->x == other.x && this->y == other.y);
	}
};



class Segment {
public:
	Point p1, p2;

	Segment() : p1(), p2() {

	}

	Segment(Point p1, Point p2) : p1(p1), p2(p2) {

	}

	Segment(float x1, float y1, float x2, float y2) : p1(x1, y1), p2(x2, y2) {

	}
};



class Line {
public:
	float a, b, c;

	Line() : a(1.f), b(0.f), c(0.f) {

	}

	Line(float a, float b, float c) {
		if (a == 0 && b == 0) {
			throw std::string("ERROR: The values of a and b cannot be zero at the same time.");
		}

		this->a = a;
		this->b = b;
		this->c = c;
	}

	Line(Point a, Point b) {
		if (a == b) {
			throw std::string("ERROR: The values a and b must be different.");
		}

		if (b.x - a.x == 0.f) {
			this->a = b.y - a.y;
			this->b = 0.f;
			this->c = a.x * (a.y - b.y);
		}

		if (b.y - a.y == 0.f) {
			this->a = 0.f;
			this->b = b.x - a.x;
			this->c = a.y * (a.x - b.x);
		}

		this->a = b.y - a.y;
		this->b = a.x - b.y;
		this->c = a.y * (b.x - a.x) - a.x * (b.y - a.y);
	}

	Line(Segment s) : Line(s.p1, s.p2) {

	}
};



class Circle {
public:
	Point centre;
	float radius;

	Circle() : centre(0.f, 0.f), radius(0.f){

	}

	Circle(float radius) : centre(0.f, 0.f) {
		if (radius < 0.f) {
			throw std::string("ERROR: Radius of a circle must be positive.");
		}
		this->radius = radius;
	}

	Circle(Point centre, float radius) : centre(centre) {
		if (radius < 0.f) {
			throw std::string("ERROR: Radius of a circle must be positive.");
		}
		this->radius = radius;
	}

	bool operator == (Circle other) {
		return (this->centre == other.centre && this->radius == other.radius);
	}
};



bool areIntersect(Line l1, Line l2) {
	if ((l1.a / l2.a == l1.b / l2.b) || (l1.a == 0 && l2.a == 0) || (l1.b == 0 && l2.b == 0)) {
		return false;
	}
	return true;
}

Point intersectionPoint(Line l1, Line l2) {
	if (!areIntersect(l1, l2)) {
		throw std::string("ERROR: Objects have 0 intersection points or they are identical.");
	}
	float x, y;
	if (l1.b == 0) {
		x = -l1.c - l1.a;
		y = (-l2.a * x - l2.c) / l2.b;
		return Point(x, y);
	}
	if (l2.b == 0) {
		x = -l2.c - l2.a;
		y = (-l1.a * x - l1.c) / l1.b;
		return Point(x, y);
	}
	x = (l2.c / l2.b - l1.c / l1.b) / (l1.a / l1.b - l2.a / l2.b);
	y = (-l1.a * x - l1.c) / l1.b;
	return Point(x, y);
}



bool areIntersect(Line l, Segment s) {
	if (!areIntersect(l, Line(s))) {
		return false;
	}
	Point p = intersectionPoint(l, Line(s));
	if (p.x < std::min(s.p1.x, s.p2.x) || p.x > std::max(s.p1.x, s.p2.x) || p.y < std::min(s.p1.y, s.p2.y) || p.y > std::max(s.p1.y, s.p2.y)) {
		return false;
	}
	return true;
}

bool areIntersect(Segment s, Line l) {
	return areIntersect(l, s);
}

Point intersectionPoint(Line l, Segment s) {
	if (!areIntersect(l, s)) {
		throw std::string("ERROR: Objects have 0 intersection points or they are identical.");
	}
	return intersectionPoint(l, Line(s));
}

Point intersectionPoint(Segment s, Line l) {
	return intersectionPoint(l, s);
}



bool areIntersect(Segment s1, Segment s2) {
	if (!areIntersect(Line(s1), Line(s2))) {
		return false;
	}
	Point p = intersectionPoint(Line(s1), Line(s2));
	if (p.x < std::max(std::min(s1.p1.x, s1.p2.x), std::min(s2.p1.x, s2.p2.x)) || p.x > std::min(std::max(s1.p1.x, s1.p2.x), std::max(s2.p1.x, s2.p2.x)) || 
		p.y < std::max(std::min(s1.p1.y, s1.p2.y), std::min(s2.p1.y, s2.p2.y)) || p.y > std::min(std::max(s1.p1.y, s1.p2.y), std::max(s2.p1.y, s2.p2.y))) {
		return false;
	}
	return true;
}

Point intersectionPoint(Segment s1, Segment s2) {
	if (!areIntersect(s1, s2)) {
		throw std::string("ERROR: Objects have 0 intersection points or they are identical.");
	}
	return intersectionPoint(Line(s1), Line(s2));
}



bool areIntersect(Circle c, Line l) {
	float distance = std::abs(l.a * c.centre.x + l.b * c.centre.y + l.c) / std::sqrt(l.a * l.a + l.b + l.b);
	if (distance > c.radius) {
		return false;
	}
	return true;
}

bool areIntersect(Line l, Circle c) {
	return areIntersect(c, l);
}

std::vector<Point> intersectionPoints(Circle c, Line l) {
	if (!areIntersect(c, l)) {
		throw std::string("ERROR: Objects have 0 intersection points or they are identical.");
	}

	float A, B, C;

	if (l.b == 0.f) {
		A = 1.f;
		B = -2.f * c.centre.y;
		C = c.centre.x * c.centre.x + (l.c * l.c) / (l.a * l.a) + (2.f * l.c * c.centre.x) / l.a + c.centre.y * c.centre.y - c.radius * c.radius;
	}
	else {
		A = 1.f + (l.a * l.a) / (l.b * l.b);
		B = -2.f * c.centre.x + (2.f * l.a * l.c) / (l.b * l.b) + (2.f * l.a * c.centre.y) / l.b;
		C = c.centre.x * c.centre.x + (l.c * l.c) / (l.b * l.b) + (2.f * l.c * c.centre.y) / l.b + c.centre.y * c.centre.y - c.radius * c.radius;
	}

	float Discriminant = B * B - 4.f * A * C;

	if (Discriminant == 0.f) {
		float x, y;
		x = (-B + std::sqrt(Discriminant)) / (2 * A);
		y = (-l.a * x - l.c) / l.b;
		return std::vector<Point> {Point(x, y)};
	}

	float x1, y1, x2, y2;
	x1 = (-B + std::sqrt(Discriminant)) / (2 * A);
	y1 = (-l.a * x1 - l.c) / l.b;
	x2 = (-B - std::sqrt(Discriminant)) / (2 * A);
	y2 = (-l.a * x2 - l.c) / l.b;
	return std::vector<Point> {Point(x1, y1), Point(x2, y2)};
}

std::vector<Point> intersectionPoints(Line l, Circle c) {
	return intersectionPoints(c, l);
}



bool areIntersect(Circle c, Segment s) {
	if (!areIntersect(c, Line(s))) {
		return false;
	}
	std::vector<Point> points = intersectionPoints(c, Line(s));
	for (auto iter = points.begin(); iter != points.end();) {
		if (iter->x < std::min(s.p1.x, s.p2.x) || iter->x > std::max(s.p1.x, s.p2.x) || iter->y < std::min(s.p1.y, s.p2.y) || iter->y > std::max(s.p1.y, s.p2.y)) {
			iter = points.erase(iter);
		}
		else {
			iter++;
		}
	}
	if (points.size() == 0) {
		return false;
	}
	return true;
}

bool areIntersect(Segment s, Circle c) {
	return areIntersect(c, s);
}

std::vector<Point> intersectionPoints(Circle c, Segment s) {
	if (!areIntersect(c, s)) {
		throw std::string("ERROR: Objects have 0 intersection points or they are identical.");
	}
	std::vector<Point> points = intersectionPoints(c, Line(s));
	for (auto iter = points.begin(); iter != points.end();) {
		if (iter->x < std::min(s.p1.x, s.p2.x) || iter->x > std::max(s.p1.x, s.p2.x) || iter->y < std::min(s.p1.y, s.p2.y) || iter->y > std::max(s.p1.y, s.p2.y)) {
			iter = points.erase(iter);
		}
		else {
			iter++;
		}
	}
	return points;
}

std::vector<Point> intersectionPoints(Segment s, Circle c) {
	return intersectionPoints(c, s);
}



bool areIntersect(Circle c1, Circle c2) {
	if (c1 == c2) {
		return false;
	}
	float distance = std::sqrt(std::pow(c1.centre.x - c2.centre.x, 2.f) * std::pow(c1.centre.y - c2.centre.y, 2.f));
	if (distance > c1.radius + c2.radius) {
		return false;
	}
	if (distance < std::max(c1.radius, c2.radius) && std::max(c1.radius, c2.radius) - distance > std::min(c1.radius, c2.radius)) {
		return false;
	}
	return true;
}

std::vector<Point> intersectionPoints(Circle c1, Circle c2) {
	if (!areIntersect(c1, c2)) {
		throw std::string("ERROR: Objects have 0 intersection points or they are identical.");
	}
}

int main() {

	return 0;
}