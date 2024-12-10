#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& cost) {
	int ans = 0;
	int cost1 = 0;
	int cost2 = 0;
	int n = cost.size();
	for (int i = 2; i < n; i++)
	{
		ans = std::min(cost1 + cost[i - 2], cost2 + cost[i - 1]);
		cost1 = cost2;
		cost2 = ans;
	}
	ans = std::min(cost1 + cost[n - 2], cost2 + cost[n - 1]);
	return ans;
}

int main()
{
	std::vector<int> v = {1,100,1,1,1,100,1,1,100,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 21.55%
