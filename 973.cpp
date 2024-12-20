#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
	std::ranges::sort(points.begin(), points.end(),[&](auto a, auto b)
			{ return a[1]*a[1] + a[0]*a[0] < b[0]*b[0] + b[1]*b[1];} );
	points.resize(k);
	return points;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 5.06%
// memory beats 5.01%
