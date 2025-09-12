#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
int minOperations(vector<int>& nums) {
	int count = 0;
	int i = 0;
	int n = nums.size();
	for (int i = 0; i <= n - 3; i++)
	{
		if (nums[i] == 0)
		{
			nums[i] = 1;
			nums[i + 1] = nums[i + 1] == 0 ? 1 : 0;
			nums[i + 2] = nums[i + 2] == 0 ? 1 : 0;
			count++;
		}
	}

	if (nums[n - 2] == 0 || nums[n - 1] == 0) return -1;
	return count;
}
int f(std::vector<int>& nums) {
	int count = 0;
	int i = 0;
	while (i < nums.size()) {
		if (nums[i] == 0) {
			if (i + 2 < nums.size()) {
				for (int j = i; j < i + 3; ++j) {
					nums[j] = 1 - nums[j];
				}
				count++;
			} else return -1;
		}
		i++;
	}
	return count;
}

int main()
{
	std::vector<int> v = {0,1,1,1,0,0};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 90.49%
// memory beats 93.66%
