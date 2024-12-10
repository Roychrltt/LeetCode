#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& prices) {
	if (prices.size() < 2) return 0;
	int profit = 0, minp = -1, maxp = -1;
	for (int i = 0; i < prices.size(); ++i)
	{
		if (i < prices.size() - 1 && prices[i] == prices[i + 1])
			continue;
		if (minp == -1 && (i < prices.size() - 1 && (i == 0 || (i > 0 && prices[i] <= prices[i - 1])) && prices[i] <= prices[i + 1]))
			minp = prices[i];
		if ((maxp == -1 && minp >= 0) && (i > 0 && (prices[i] >= prices[i - 1]) && (i == prices.size() - 1 || prices[i] >= prices[i + 1])))
			maxp = prices[i];
		if (minp >= 0 && maxp >= 0)
		{
			profit += maxp - minp;
			maxp = -1;
			minp = -1;
		}
	}
	return profit;
}

int main()
{
	std::vector<int> v = {7,1,5,3,6,4};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 91.94%
