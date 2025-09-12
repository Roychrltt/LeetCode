#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::string s) {
	return std::ranges::any_of(s, [](char c) {
			return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
			});
}

int main()
{
	std::string s = "onceuponatime";
	bool ans = f(s);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 13.58%
