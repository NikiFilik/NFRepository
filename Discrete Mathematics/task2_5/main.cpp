#include <iostream>

class Pair {
public:
	int a, b;
};

int main() {
	const int H = 20, V = 17;
	Pair field[V + 1][H + 1];

	for (int i = 1; i <= H; i++) {
		field[0][i].a = 1;
		field[0][i].b = 0;
	}

	field[1][0].a = 0;
	field[1][0].b = 1;
	for (int i = 2; i <= V; i++) {
		field[i][0].a = 0;
		field[i][0].b = 0;
	}

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= H; j++) {
			field[i][j].a = field[i][j - 1].a + field[i][j - 1].b;
			field[i][j].b = field[i - 1][j].a;
		}
	}

	std::cout << field[V][H].a + field[V][H].b;
	return 0;
}