#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::string s, std::string t) {
	if (s.length() != t.length())
		return false;
	std::vector<int> v1(26);
	std::vector<int> v2(26);
	for (int i = 0; i < s.length(); i++)
		v1[s[i] - 'a']++;
	for (int i = 0; i < t.length(); i++)
		v2[t[i] - 'a']++;
	for (int i = 0; i < v1.size(); i++)
		if (v1[i] != v2[i])
			return false;
	return true;
}

int main()
{
	std::string s = "akakakakbdbdbdbd";
	std::string t = "ababababdkdkdkdk";
	bool ans = f(s, t);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 42.85%
