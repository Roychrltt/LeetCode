#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	int sum = 0;
	for (int i = 0; i < nums.size(); i += 2)
		sum += nums[i];
	return sum;
}

int main()
{
	std::vector<int> v = {6,2,6,5,1,2};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 85.93%
