#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> finalPrices(std::vector<int>& prices) {
	int n = prices.size();
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (prices[j] <= prices[i])
			{
				prices[i] -= prices[j];
				break;
			}
		}
		ans[i] = prices[i];
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
// runtime beats 100%
// memory beats 24.39%
