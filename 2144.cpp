#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& cost) {
	std::sort(cost.begin(), cost.end(), std::greater<int>());
	int res = 0;
	int n = cost.size();
	for (int i = 0; i < n; ++i) {
		if (i % 3 != 2) {
			res += cost[i];
		}
	}
	return res;
}

int main()
{
	std::vector<int> v = {1,2,3,4,5,6};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 26.03%
