#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int ans = 1;
	std::vector<bool> v(26, false);
	for (char c : s) {
		int x = c - 'a';
		if (v[x]) {
			ans++;
			std::fill(v.begin(), v.end(), false);
		}
		v[x] = true;
	}
	return ans;
}

int main()
{
	std::string s = "absbdbbdabbabbdb";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 83.97%
// memory beats 63.47%
