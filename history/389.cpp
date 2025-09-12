#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

char findTheDifference(std::string s, std::string t) {
	int ret = 0;
	for (char ch: s)
		ret ^= ch;

	for (char ch: t)
		ret ^= ch;

	return ret;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 49.25%
