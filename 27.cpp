#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int removeElement(vector<int>& nums, int val) {
	int k = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] != val)
			nums[k++] = nums[i];
	}
	return k;     
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 27.74%
