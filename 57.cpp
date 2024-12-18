#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> f(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
	auto beg = intervals.begin(), end = intervals.end();
	int& a = newInterval[0], & b = newInterval[1];
	auto l = lower_bound(beg, end, a, [](auto& val, int b) { return val[1] < b; });
	auto r = upper_bound(  l, end, b, [](int b, auto& val) { return val[0] > b; });
	if (l != end) a = std::min(a, l[ 0][0]);
	if (r != beg) b = std::max(b, r[-1][1]);
	intervals.insert(intervals.erase(l, r), newInterval);
	return intervals;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 20.20%
