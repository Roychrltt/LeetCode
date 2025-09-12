#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int ans = 0;
	for (int i = 1; i < s.length(); i++) {
		if (abs(s[i - 1] - s[i]) <= 1) {
			ans++;
			i++;
		}
	}
	return ans;
}

int main()
{
	std::string s = "zyxyxyz";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 22.44%
