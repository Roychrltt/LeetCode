#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& nums) {
	std::unordered_map<int, int> map;
	int n = nums.size();

	for (int x : nums) {
		map[x]++;
		if (map[x] > n / 2)
			return x;
	}

	return 0;         
}

int main()
{
	std::vector<int> v = {2,2,1,1,1,2,2};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 13.17%
