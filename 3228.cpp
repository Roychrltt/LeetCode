#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int cnt = s[0] == '1' ? 1 : 0;
	int ans = 0;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == '1')
			cnt++;
		else if (s[i - 1] == '1')
			ans += cnt;
	}
	return ans;
}

int main()
{
	std::string s = "1001101";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 23.29%
