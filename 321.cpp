#include <bits/stdc++.h>

class Solution {
	public:
		vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
			int n = nums1.size(), m = nums2.size();
			vector<int> ans(k);
			for (int i = max(0, k - m); i <= k && i <= n; ++i) {
				vector<int> candidate = merge(maxArray(nums1, i), maxArray(nums2, k - i), k);
				if (greater(candidate, 0, ans, 0)) ans = candidate;
			}
			return ans;
		}

	private:
		vector<int> merge(const vector<int>& nums1, const vector<int>& nums2, int k) {
			vector<int> ans(k);
			int i = 0, j = 0;
			for (int r = 0; r < k; ++r)
				ans[r] = greater(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
			return ans;
		}

		bool greater(const vector<int>& nums1, int i, const vector<int>& nums2, int j) {
			while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
				++i;
				++j;
			}
			return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
		}

		vector<int> maxArray(const vector<int>& nums, int k) {
			int n = nums.size();
			vector<int> ans(k);
			int j = 0;
			for (int i = 0; i < n; ++i) {
				while (n - i + j > k && j > 0 && ans[j - 1] < nums[i]) --j;
				if (j < k) ans[j++] = nums[i];
			}
			return ans;
		}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 84.24%
// memory beats 93.07%
