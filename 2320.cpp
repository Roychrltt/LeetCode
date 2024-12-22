#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countHousePlacements(int n) {
	const int MOD = 1e9 + 7;
	std::vector<int> dp(n + 1);
	dp[0] = 1, dp[1] = 2;
	for (int i = 2; i <= n; ++i)
		dp[i] = (static_cast<long long>(dp[i - 1] + dp[i - 2])) % MOD;
	return static_cast<long long>(dp[n]) * dp[n] % MOD;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 47.30%
