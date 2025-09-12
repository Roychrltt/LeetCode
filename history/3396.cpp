#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimumOperations(vector<int>& nums) {
	int count = 0;
	int n = nums.size();
	vector<int> cnt(101, 0);
	for (int i = n - 1; i >= 0; i--)
	{
		if (cnt[nums[i]]++ > 0)
			break;
		cnt[nums[i]] = nums[i];
		count++;
	}
	return (n - count + 2) / 3;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 90.53%
