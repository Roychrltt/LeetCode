#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long f(std::vector<int>& nums1, std::vector<int>& nums2, int k1, int k2) {
	std::vector<int> v(1e5 + 1, 0);
	int n = nums1.size();
	for (int i = 0; i < n; i++)
		v[std::abs(nums1[i] - nums2[i])]++;
	int k = k1 + k2;
	for (int i = v.size() - 1; k > 0 && i > 0; i--) {
		int c = std::min(k, v[i]);
		v[i - 1] += c;
		k -= c;
		v[i] -= c;
	}
	long long ans = 0;
	for (long long i = 0; i < 1e5 + 1; i++) {
		if (v[i] != 0) {
			ans += i * i * v[i];
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v1 = {1,4,10,12};
	std::vector<int> v2 = {5,8,6,9};
	long long int ans = f(v1, v2,1,1);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 80.25%
// memory beats 20.20%
