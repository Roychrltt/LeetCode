#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void moveZeroes(std::vector<int>& nums) {
	int left = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i])
			std::swap(nums[i], nums[left++]);
	}
}

int main()
{
	std::vector<int> v = {1,0,2,3,0,0,8,9};
	moveZeroes(v);
	return 0;
}
// runtime beats 100%
// memory beats 25.52%
