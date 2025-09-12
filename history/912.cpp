#include <bits/stdc++.h>

class Solution {
	void shellSort(vector<int>& nums, int n)
	{
		for (int gap = n / 2; gap > 0; gap /= 2)
		{
			for (int i = gap; i < n; i++)
			{
				int x = nums[i];
				int j = i - gap;
				while (j >= 0 && nums[j] > x)
				{
					nums[j + gap] = nums[j];
					j = j - gap;
				}
				nums[j + gap] = x;
			}
		}
	}
	public:
	vector<int> sortArray(vector<int>& nums) {
		if (nums.size() < 2) return nums;
		shellSort(nums, nums.size());
		return nums;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 77.28%
// memory beats 72.76%
