#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>

int f(std::vector<int>& nums1, std::vector<int>& nums2) {
	if (6 * nums1.size() < nums2.size() || 6 * nums2.size() < nums1.size())
		return -1;
	int d = std::accumulate(nums2.begin(), nums2.end(), 0) -
		std::accumulate(nums1.begin(), nums1.end(), 0);
	if (d < 0) {
		d = -d;
		std::swap(nums1, nums2);
	}
	int cnt[6]{};
	for (int x : nums1)
		++cnt[6 - x];
	for (int x : nums2)
		++cnt[x - 1];
	int ans = 0;
	for (int i = 5; i >= 0; --i) {
		if (i * cnt[i] >= d)
			return ans + (d + i - 1) / i;
		ans += cnt[i];
		d -= i * cnt[i];
	}
	return ans;
}

int main()
{
	std::vector<int> v1 = {1,2,3,4,5,6};
	std::vector<int> v2 = {1,1,2,2,2,2};
	int ans = f(v1, v2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 65.24%
