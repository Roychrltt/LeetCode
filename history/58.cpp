#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int lengthOfLastWord(std::string s) {
	int count = 0;
	int n = s.length() - 1;
	while (n >= 0 && s[n] == 32)
	{
		n--;
	}
	while (n >= 0 && s[n] != 32)
	{
		count++;
		n--;
	}
	return count;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 44.02%
