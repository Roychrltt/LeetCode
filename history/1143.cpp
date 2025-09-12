#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int longestCommonSubsequence(string s, string t) {
	int n1 = s.size(), n2 = t.size();
	vector<int> dp(n1, 0);
	int ans = 0;

	for (char c : t) {
		int cur = 0;
		for (int i = 0; i < n1; i++) {
			if (cur < dp[i])
				cur = dp[i];
			else if (c == s[i])
				dp[i] = cur + 1;
			ans = max(ans, dp[i]);
		}
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
// runtime beats 99.37%
// memory beats 98.92%
