#include <bits/stdc++.h>

vector<int> findCoins(vector<int>& numWays) {
	int N = numWays.size();
	vector<long long> dp(N+1, 0);
	dp[0] = 1;
	vector<int> coins;

	for (int i = 1; i <= N; ++i) {
		long long int target = numWays[i-1];
		if (dp[i] == target - 1) {
			coins.push_back(i);
			for (int j = i; j <= N; ++j)
				dp[j] += dp[j - i];
		}
		if (dp[i] != target)
			return {};
	}
	return coins;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
