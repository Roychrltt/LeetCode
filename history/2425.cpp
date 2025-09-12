#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int xorAllNums(std::vector<int>& nums1, std::vector<int>& nums2) {
	int m = nums1.size(), n = nums2.size();
	int ans = 0;
	if (n % 2)
		for (int x : nums1) ans ^= x;
	if (m % 2)
		for (int x : nums2) ans ^= x;

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
// memory beats 82.93%
