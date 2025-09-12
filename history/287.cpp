#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findDuplicate(vector<int>& nums) {
	int slow = nums[0], fast = nums[0];

	while (true)
	{
		slow = nums[slow];
		fast = nums[nums[fast]];
		if (slow == fast) break;
	}

	int x = nums[0];
	while (slow != x)
	{
		slow = nums[slow];
		x = nums[x];
	}
	return x;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 69.73%
