#include <bits/stdc++.h>

bool hasTrailingZeros(vector<int>& nums) {
	int count = 0;
	for (int x : nums)
	{
		if (!(x & 1))
			count++;
	}
	return count > 1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 98.06%
