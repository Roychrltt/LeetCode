#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countGoodStrings(int low, int high, int zero, int one) {
	const int MOD = 1e9 + 7;
	std::vector<int> dp(high + 1);
	dp[0] = 1;

	for (int i = 1; i <= high; i++)
	{
		if (i >= zero)
			dp[i] = static_cast<long long>(dp[i] + dp[i - zero]) % MOD;
		if (i >= one)
			dp[i] = static_cast<long long>(dp[i] + dp[i - one]) % MOD;
	}
	int ans = 0;
	for (int i = low; i <= high; i++)
	{
		ans = static_cast<long long>(ans + dp[i]) % MOD;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 98.57%
// memory beats 69.71%
