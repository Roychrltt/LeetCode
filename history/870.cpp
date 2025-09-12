#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

std::vector<int> f(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::sort(nums1.begin(), nums1.end());
	int n = nums1.size();
	std::vector<int> ids(n);
	std::iota(ids.begin(), ids.end(), 0);
	std::ranges::sort(ids, [&](int i, int j) { return nums2[i] < nums2[j]; });

	std::vector<int> ans(n);
	int left = 0, right = n - 1;
	for (int x : nums1) {
		ans[x > nums2[ids[left]] ? ids[left++] : ids[right--]] = x;
	}
	return ans;
}

int main()
{
	std::vector<int> v1 = {12,24,8,32};
	std::vector<int> v2 = {13,25,32,11};
	std::vector<int> v = f(v1, v2);
	for (auto i : v)
		std::cout << i << std::endl;
	return 0;
}
// runtime beats 78.28%
// memory beats 92.56%
