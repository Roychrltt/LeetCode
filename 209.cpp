#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minSubArrayLen(int target, std::vector<int>& nums) {
	int n = nums.size();
	std::vector<int> v(n + 1);
	for (int i = 1; i < n + 1; i++)
		v[i] = v[i - 1] + nums[i - 1];
	if (v[n] < target) return 0;
	int ans = n + 1;
	int j = n - 1;
	for (int i = n; i > 0; i--)
	{
		if (v[i] < target) break;
		while (v[i] - v[j] < target)
			j--;
		ans = std::min(ans, i - j);
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
// memory beats 5.63%
