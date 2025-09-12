#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long f(std::vector<int>& nums) {
	long long sum = nums.back();
	for (int i = nums.size() - 2; i >= 0; i--) {
		sum = nums[i] <= sum ? sum + nums[i] : nums[i];
	}
	return sum;
}

int main()
{
	std::vector<int> v = {2,3,7,9,3};
	long long ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 46.24%
