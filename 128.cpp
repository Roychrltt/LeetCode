#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int longestConsecutive(std::vector<int>& nums) {
	std::unordered_set<int> st(nums.begin(), nums.end());
	int ans = 0;
	for (int x : st)
	{
		int len = 0;
		if (st.contains(x - 1)) continue;
		while (st.contains(x++))
			len++;
		ans = std::max(ans, len);
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 55.16%
// memory beats 5.23%
