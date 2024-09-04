#include <iostream>
#include <cmath>

int main() {
    setlocale(LC_ALL, "Russian");

    long long x;

    std::cout << "¬ведите число x:\n";
    std::cin >> x;

    std::cout << "»скомые числа, меньшие чем x:\n";
    for (int k = 0; k <= log(x) / log(3); k++) {
        for (int l = 0; l <= log(x) / log(5); l++) {
            for (int m = 0; m <= log(x) / log(7); m++) {
                long long num;
                num = std::pow(3, k) + std::pow(5, l) + std::pow(7, m);
                if (num <= x) {
                    std::cout << num << "\n";
                }
            }
        }
    }

    return 0;
}