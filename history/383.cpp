#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::string ransomNote, std::string magazine) {
	std::unordered_map<char, int> map;

	for (char c : magazine) {
		map[c]++;
	}

	for (char c : ransomNote) {
		if (map[c] <= 0)
			return false;
		map[c]--;
	}

	return true;
}

int main()
{
	std::string s1 = "abcd";
	std::string s2 = "aabb";
	bool ans = f(s1, s2);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 10.23%
