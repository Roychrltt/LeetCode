#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int knapsack(std::vector<int> &values, std::vector<int> &weights, int capacity)
{
	int n = values.size();
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1));
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 0; j < capacity + 1; j++)
		{
			if (j < weights[i])
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = std::max(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
		}
	}
	return dp[n][capacity];
}

int main()
{
	std::vector<int> values = {1,2,3,4,6,8};
	std::vector<int> weights = {1,3,2,8,6,4};
	int capacity = 10;
	int ans = knapsack(values, weights, capacity);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
