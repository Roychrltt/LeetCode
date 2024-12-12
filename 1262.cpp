#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

int f(std::vector<int> &nums) {
	int s = std::accumulate(nums.begin(), nums.end(), 0);
	if (s % 3 == 0)
		return s;

	std::vector<int> a[3];
	for (int x: nums)
		a[x % 3].push_back(x);
	std::sort(a[1].begin(), a[1].end());
	std::sort(a[2].begin(), a[2].end());

	if (s % 3 == 2)
		swap(a[1], a[2]);
	int ans = a[1].size() ? s - a[1][0] : 0;
	if (a[2].size() > 1)
		ans = std::max(ans, s - a[2][0] - a[2][1]);
	return ans;
}

int main()
{
	std::vector<int> v = {3,5,6,8,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 81.72%
// memory beats 74.46%
