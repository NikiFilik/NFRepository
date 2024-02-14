#include <iostream>
#include <cmath>

class Cuboid {
private:
	int side_a, side_b, side_c;
public:
	void set_a(int a) {
		side_a = a;
	}
	void set_b(int b) {
		side_b = b;
	}
	void set_c(int c) {
		side_c = c;
	}

	int get_a() {
		return side_a;
	}
	int get_b() {
		return side_b;
	}
	int get_c() {
		return side_c;
	}

	int square() {
		return 2*side_a*side_b + 2*side_a*side_c + 2*side_b*side_c;
	}
	int volume() {
		return side_a*side_b*side_c;
	}
	float diagonal(){
		return sqrt(side_a*side_a + side_b*side_b + side_c*side_c);
	}
};

int main() {
	Cuboid brick;

	brick.set_a(5);
	brick.set_b(10);
	brick.set_c(3);

	std::cout << brick.get_a() << std::endl;
	std::cout << brick.get_b() << std::endl;
	std::cout << brick.get_c() << std::endl;

	std::cout << brick.square() << std::endl;
	std::cout << brick.volume() << std::endl;
	std::cout << brick.diagonal() << std::endl;
	return 0;
}