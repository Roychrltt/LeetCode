#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& cost) {
	int cost1 = 0;
	int cost2 = 0;
	for (int i = 1; i < cost.size(); i++)
	{
		int ans = std::min(cost1 + cost[i], cost2 + cost[i - 1]);
		cost2 = cost1;
		cost1 = ans;
	}
	return cost1;
}

int main()
{
	std::vector<int> v = {1,100,1,1,1,100,1,1,100,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 38.96%
