#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<int>> f(std::vector<int>& nums) {
	std::vector<std::vector<int>> ans;
	std::sort(nums.begin(), nums.end());
	int n = nums.size();
	for (int i = 0; i < n - 2; ++i)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		int j = i + 1;
		int k = n - 1;
		while (j < k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			if (sum > 0)
				k--;
			else if (sum < 0)
				j++;
			else
			{
				ans.push_back({nums[i], nums[j], nums[k]});
				j++;
				while (nums[j] == nums[j - 1] && j < k)
					j++;
				while (nums[k] == nums[k - 1] && j < k)
					k--;
			}
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v = {1,0,-1,2,-1,-4};
	std::vector<std::vector<int>> ans = f(v);
	for (auto row : ans)
		for (auto i : row)
			std::cout << i << std::endl;
	return 0;
}
// runtime beats 76.20%
// memory beats 90.83%
