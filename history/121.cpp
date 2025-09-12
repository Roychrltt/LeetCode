#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxProfit(vector<int>& prices) {
	int cost = std::numeric_limits<int>::max();
	int profit = 0;
	for (int p : prices)
	{
		cost = std::min(p, cost);
		profit = std::max(profit, p - cost);
	}
	return profit;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 29.56%
// memory beats 32.24%
