#include <iostream>
#include <vector>

const int INF = INT_MAX;

int tsp(int mask, int pos, const std::vector<std::vector<int>>& dist, std::vector<std::vector<int>>& dp) {
    if (mask == (1 << dist.size()) - 1) {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INF;

    for (int city = 0; city < dist.size(); city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city, dist, dp);
            ans = std::min(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    std::vector<std::vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int n = dist.size();

    std::vector<std::vector<int>> dp(1 << n, std::vector<int>(n, -1));

    int result = tsp(1, 0, dist, dp);

    std::cout << result << "\n";

    return 0;
}