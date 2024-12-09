#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

int f(std::vector<std::vector<int>>& boxTypes, int truckSize) {
	std::sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
	int ans = 0;
	for (auto& e : boxTypes) {
		int a = e[0], b = e[1];
		ans += b * std::min(truckSize, a);
		truckSize -= a;
		if (truckSize <= 0) break;
	}
	return ans;
}

int main()
{
	std::vector<std::vector<int>> v = {{1,3}, {2,2}, {3,1}};
	int ans = f(v, 4);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 76.08%
// memory beats 76.96%
