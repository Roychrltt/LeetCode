#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
	if (obstacleGrid[0][0] == 1)
		return 0;
	dp[0][0] = 1;
	for (int i = 1; i < m; i++)
		if (obstacleGrid[i][0] != 1)
			dp[i][0] = dp[i - 1][0];
	for (int j = 1; j < n; j++)
		if (obstacleGrid[0][j] != 1)
			dp[0][j] = dp[0][j - 1];
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (obstacleGrid[i][j] == 1)
				dp[i][j] = 0;
			else
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[m - 1][n - 1];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// dpry beats 15.19%
