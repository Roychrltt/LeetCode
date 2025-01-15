#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int singleNumber(std::vector<int>& nums) {
	vector<int> v(32, 0);
	for (int num : nums)
		for (int i = 0; i<32; i++)
			v[i] += (num >> i) & 1;
	int ans = 0;
	for (int i = 0; i < 32; i++)
		if (v[i] % 3 != 0)
			ans |= 1 << i;
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
// memory beats 37.63%
