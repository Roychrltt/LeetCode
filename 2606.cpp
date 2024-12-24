#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
	std::vector<int> v(26, 0);
	for (int i = 0; i < vals.size(); i++)
		v[chars[i] - 'a'] = vals[i];
	for (int i = 0; i < 26; i++)
	{
		if (chars.find(i + 'a') == std::string::npos)
			v[i] = i + 1;
	}
	int ans = 0;
	int preSum = 0;
	int minPreSum = 0;
	for (char c : s)
	{
		preSum += v[c - 'a'];
		ans = std::max(ans, preSum - minPreSum);
		minPreSum = std::min(minPreSum, preSum);
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
// runtime beats 100%
// memory beats 63.87%
