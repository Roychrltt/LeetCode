#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int deleteAndEarn(std::vector<int>& nums) {
	std::unordered_map<int, int> map;
	for (int x : nums)
		map[x]++;
	std::vector<std::pair<int, int>> v;
	for (auto p : map)
		v.emplace_back(p.first, p.second);
	std::sort(v.begin(), v.end());
	int n = v.size();
	std::vector<int> dp(n);
	dp[0] = v[0].first * v[0].second;
	if (n == 1)
		return dp[0];
	int temp = v[1].first * v[1].second;
	dp[1] = v[1].first - 1 == v[0].first ? std::max(dp[0], temp) : dp[0] + temp;
	for (int i = 2; i < n; i++)
	{
		int cur = v[i].first * v[i].second;
		dp[i] = v[i - 1].first == v[i].first - 1 ? std::max(dp[i - 1], dp[i - 2] + cur) : dp[i - 1] + cur;
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
// runtime beats 67.15%
// memory beats 38.53%
