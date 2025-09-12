#include <bits/stdc++.h>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        for (int c : coins)
            for (int i = c; i <= amount; i++)
                dp[i] += dp[i - c];

        return dp[amount];
    }
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 89.21%
// memory beats 83.90%
