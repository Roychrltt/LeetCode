#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<std::vector<int>>& points, int w) {
	std::ranges::sort(points, [](const auto& p, const auto& q) {
			return p[0] < q[0]; });
	int ans = 0;
	int x2 = -1;
	for (auto& p : points) {
		if (p[0] > x2) {
			ans++;
			x2 = p[0] + w;
		}
	}
	return ans;
}

int main()
{
	std::vector<std::vector <int>> v = {{2,1}, {1,0}, {1,4}, {1,8}, {3,5}, {4,6}};
	int ans = f(v, 1);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 52.94%
// memory beats 38.46%
