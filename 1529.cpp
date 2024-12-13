#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int count = 0;
	char prev = '0';
	for (int i = 0; i < s.length(); i++) {
		char curr = s[i];
		if (curr != prev) {
			count++;
			prev = curr;
		}
	}
	return count;
}

int main()
{
	std::string s = "10111";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 8.26%
