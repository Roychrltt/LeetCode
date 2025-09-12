#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int uniquePaths(int m, int n) {
	int ans = 1;
	int j = 1;
	for (int i = m + n - 2; i >= max(m, n); i--)
		ans = ((long long)ans * i) / j++;
	return ans;
}

int uniquePaths(int m, int n) {
	std::vector<std::vector<int>> dp(m, std:vector<int>(n, 1));
	for(int i = 1; i < m; i++)
		for(int j = 1; j < n; j++)
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
	return dp[m-1][n-1];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 81.56%
