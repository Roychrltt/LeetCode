#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findMaxConsecutiveOnes(vector<int>& nums) {
	int ans = 0;
	int n = nums.size();
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		while (i < n && nums[i] == 1)
		{
			count++;
			i++;
		}
		ans = std::max(count, ans);
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
// memory beats 52.12%
