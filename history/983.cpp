#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
	std::vector<bool> year(366, false);
	for (int x : days) year[x] = true;

	int n = days.size();
	std::vector<int> dp(days[n - 1] + 1, 0);
	dp[days[0]] = std::min(costs[0], std::min(costs[1], costs[2]));
	for (int i = days[0] + 1; i <= days[n - 1]; i++)
	{
		if (!year[i])
			dp[i] = dp[i - 1];
		else
			dp[i] = std::min(dp[i - 1] + costs[0], std::min(dp[std::max(i - 7, 0)] + costs[1], dp[std::max(i - 30, 0)] + costs[2]));
	}
	return dp[days[n - 1]];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 59.41%
