#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void comp(std::vector<int>& a)
{
	for (int& x : a)
		if (x % 2)
			x = -x;
	std::sort(a.begin(), a.end());
}

long long f(std::vector<int>& nums, std::vector<int>& target) {
	comp(nums);
	comp(target);
	long long ans = 0L;
	for (int i = 0; i < nums.size(); ++i)
		ans += abs(nums[i] - target[i]);
	return ans / 4;
}

int main()
{
	std::vector<int> v1 = {1,2,5};
	std::vector<int> v2 = {4,1,3};
	long long ans = f(v1, v2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 79.52%
// memory beats 90.53%
