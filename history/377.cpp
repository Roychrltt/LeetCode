#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums, int target) {
	std::vector<unsigned> f(target + 1, 0);
	f[0] = 1;
	for (int i = 1; i <= target; i++)
	{
		for (int num : nums)
			if (num <= i)
				f[i] += f[i - num];
	}
	return f[target];
}

int main()
{
	std::vector<int> v = {1,2,3};
	int ans = f(v, 5);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 26.93%
