#include <bits/stdc++.h>

class Solution {
	int find(vector<int>& nums, int l, int r, int k)
	{
		if (l == r) return nums[k];

		int p = nums[l], i = l - 1, j = r + 1;
		while (i < j)
		{
			do i++; while (nums[i] < p);
			do j--; while (nums[j] > p);
			if (i < j)
				swap(nums[i], nums[j]);
		}
		if (k <= j) return find(nums, l, j, k);
		else return find(nums, j + 1, r, k);
	}
	public:
	int findKthLargest(vector<int>& nums, int k) {
		int n = nums.size();
		return find(nums, 0, n - 1, n - k);
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 94.03%
// memory beats 82.78%
