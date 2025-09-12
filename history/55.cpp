#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::vector<int>& nums) {
	int m = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > m)
			return false;
		m = std::max(m, i + nums[i]);
		if (m >= nums.size() - 1)
			return true;
	} 
	return false;
}

int main()
{
	std::vector<int> v = {3,2,1,0,4};
	bool ans = f(v);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 59.59%
