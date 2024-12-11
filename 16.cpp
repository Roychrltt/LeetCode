#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	std::ranges::sort(nums);
	int closestSum = INT_MAX / 2;
	int n = nums.size();
	for (int i = 0; i < n - 2; ++i) {
		int j = i + 1, k = n - 1;
		while (j < k) {
			int sum = nums[i] + nums[j] + nums[k];
			if (std::abs(sum - target) < std::abs(closestSum - target))
				closestSum = sum;
			if (sum < target)
				j++;
			else if (sum > target)
				k--;
			else
				return sum;
		}
	}
	return closestSum;
}

int main()
{
	std::vector<int> v = {4,8,6,1,10,9,77,2,-11,-20};
	int ans = f(v, 10);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 84.65%
// memory beats 57.07%
