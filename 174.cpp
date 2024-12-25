#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int m = dungeon.size(), n = dungeon[0].size();
	std::vector<std::vector<int>> dp(m, std::vector<int>(n));
	dp[m - 1][n - 1] = dungeon[m - 1][n - 1] >= 0 ? 1 : -dungeon[m - 1][n - 1] + 1;
	for (int i = m - 2; i >= 0; i--)
	{
		int tmp = dp[i + 1][n - 1] - dungeon[i][n - 1];
		dp[i][n - 1] = tmp <= 0 ? 1 : tmp;
	} 
	for (int i = n - 2; i >= 0; i--)
	{
		int tmp = dp[m - 1][i + 1] - dungeon[m - 1][i];
		dp[m - 1][i] = tmp <= 0 ? 1 : tmp;
	}
	for (int i = m - 2; i >= 0; i--)
	{
		for (int j = n - 2; j >= 0; j--)
		{
			int tmp1 = dp[i][j + 1] - dungeon[i][j];
			int tmp2 = dp[i + 1][j] - dungeon[i][j];
			if (tmp1 <= 0) tmp1 = 1;
			if (tmp2 <= 0) tmp2 = 1;
			dp[i][j] = std::min(tmp1, tmp2);
		}
	}
	return dp[0][0];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 23.61%
