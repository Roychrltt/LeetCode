#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int a = m - 1, b = n - 1;
	for (int i = m + n - 1; i >= 0; i--)
	{
		if (b < 0 || (a >= 0 && nums1[a] >= nums2[b]))
			nums1[i] = nums1[a--];
		else
			nums1[i] = nums2[b--];
	}
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 6.36%
