#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int coinChange(vector<int>& coins, int amount) {
	vector<int> dp(amount + 1, amount + 1);
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i) {
		for (int coin : coins) {
			if (coin <= i)
				dp[i] = min(dp[i], dp[i - coin] + 1);
		}
	}
	return dp[amount] > amount ? -1 : dp[amount];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 92.68%
// memory beats 59.96%
