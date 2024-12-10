#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& costs, int coins) {
	std::sort(costs.begin(), costs.end());
	int count = 0;
	for (int i = 0; i < costs.size(); i++) {
		int cost = costs[i];
		if (coins >= cost) {
			coins -= cost;
			count++;
		} else {
			break;
		}
	}
	return count;
}

int main()
{
	std::vector<int> v = {1,3,2,4,1};
	int ans = f(v, 7);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 53.30%
// memory beats 88.12%
