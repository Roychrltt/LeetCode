#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int removeDuplicates(std::vector<int>& nums) {
	int prev = nums[0];
	int n = nums.size();
	int k = 1;
	for (int i = 1; i < n; i++)
	{
		nums[k++] = nums[i];
		if (nums[i] != prev)
			prev = nums[i];
		else
		{
			while (i < n - 1 && nums[i] == nums[i + 1])
				i++;
		}
	}
	return k;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 76.90%
// memory beats 56.70%
