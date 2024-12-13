#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

long long f(std::string s) {
	long long ans = 0;
	int n = s.length();
	for (int i = 1; i < n; i++)
	{
		if (s[i - 1] != s[i])
		{
			ans += std::min(i, n - i);
		}
	}
	return ans;
}

int main()
{
	std::string s = "01010010000110010110100";
	long long ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 37.69%
