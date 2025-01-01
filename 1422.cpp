#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxScore(string s) {
	int count = 0;
	for (char c : s)
		if (c == '1')
			count++;
	int ans = 0;
	int zero = s[0] == '0' ? 1 : 0;
	int n = s.length();
	for (int i = 1; i < n; i++)
	{
		ans = std::max(ans, count - i + 2 * zero);
		if (s[i] == '0') zero++;
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
// memory beats 52.60%
