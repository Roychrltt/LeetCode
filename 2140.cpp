#include <bits/stdc++.h>

long long mostPoints(vector<vector<int>>& qs) {
	int n = qs.size();
	vector<long long> dp(n, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		dp[i] = qs[i][0];
		int j = i + qs[i][1] + 1;
		if (j < n) dp[i] += dp[j];
		if (i < n - 1) dp[i] = max(dp[i], dp[i + 1]);
	}
	return dp[0];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 58.89%
