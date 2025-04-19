#include <iostream>
#include <vector>

std::vector<int> DP;

int dp(std::vector<int> weights, int capacity, int mask) {
    if (mask == 0) {
        DP[mask] = 0;
        return 0;
    }

    int minNumOfContainers = weights.size();
    int remaining = mask;

    while (remaining) {
        int weight = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (remaining & (1 << i)) {
                weight += weights[i];
            }
        }

        if (weight <= capacity) {
            if (DP[mask ^ remaining] == -1) {
                minNumOfContainers = std::min(minNumOfContainers, 1 + dp(weights, capacity, mask ^ remaining));
            }
            else {
                minNumOfContainers = std::min(minNumOfContainers, 1 + DP[mask ^ remaining]);
            }
        }

        remaining = (remaining - 1) & mask;
    }

    DP[mask] = minNumOfContainers;
    return minNumOfContainers;
}

int main() {
    std::vector<int> weights{10, 6, 5, 5, 3, 3, 3, 3, 2};
    int capacity = 20;

    for (int i = 0; i < (1 << weights.size()); i++) {
        DP.push_back(-1);
    }

    std::cout << dp(weights, capacity, (1 << weights.size()) - 1);

    return 0;
}