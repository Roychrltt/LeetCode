#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

vector<int> findDisappearedNumbers(vector<int>& nums) {
	for (int x : nums)
		if (nums[abs(x) - 1] > 0) nums[abs(x) - 1] *= -1;
	vector<int> ans;
	for (int i = 0; i < nums.size(); i++)
		if (nums[i] > 0)
			ans.push_back(i + 1);
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 89.07%
// memory beats 73.22%
