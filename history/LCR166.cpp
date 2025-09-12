#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<std::vector<int>>& frame)
{
	int row = frame.size();
	if (row == 0) return 0;
	int col = frame[0].size();
	std::vector<std::vector<int>> dp(row, std::vector<int>(col));
	dp[0][0] = frame[0][0];
	for (int i = 1; i < col; i++)
		dp[0][i] = frame[0][i] + dp[0][i - 1];
	for (int i = 1; i < row; i++)
		dp[i][0] = frame[i][0] + dp[i - 1][0];
	for (int i = 1; i < row; i++)
	{
		for (int j = 1; j < col; j++)
		{
			dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + frame[i][j];
		}
	}
	return dp[row - 1][col - 1];
}

int f(std::vector<std::vector<int>>& frame)
{
	int m = grid.size(), n = grid[0].size(), f[m + 1][n + 1];
	memset(f, 0, sizeof(f));
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			f[i + 1][j + 1] = max(f[i + 1][j], f[i][j + 1]) + grid[i][j];
	return f[m][n];
}

int main()
{
	std::vector<std::vector<int>> v = {{1,3,4,5}, {2,5,4,3}, {4,10,2,3}, {8,9,7,6}};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
