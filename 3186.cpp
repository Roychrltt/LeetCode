#include <bits/stdc++.h>

long long maximumTotalDamage(std::vector<int>& power) {
	std::unordered_map<int, long long> map;
	for (int d : power) {
		map[d]++;
	}

	vector<int> set;
	for (const auto& [a, _] : map) {
		set.push_back(a);
	}
	sort(set.begin(), set.end());

	int n = set.size();
	std::vector<long long> dp(n, 0);

	dp[0] = set[0] * map[set[0]];

	for (int i = 1; i < n; i++) {
		int cur = set[i];
		long long curD = cur * map[cur];

		dp[i] = dp[i - 1];

		int j = i - 1;
		while (j >= 0 && set[j] + 2 >= cur) {
			j--;
		}

		if (j >= 0)
			dp[i] = std::max(dp[i], dp[j] + curD);
		else
			dp[i] = std::max(dp[i], curD);
	}

	return dp[n - 1];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 75.89%
// memory beats 43.74%
