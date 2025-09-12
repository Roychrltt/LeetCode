#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string f(const std::string& s) {
	int n = s.length();
	std::string str(n * 2 + 1, 0);
	for (int i = 0; i < n * 2 + 1; i++)
	{
		if (i % 2 == 0)
			str[i] = '#';
		else
			str[i] = s[i / 2];
	}
	int begin = 0, maxLen = 0;
	for (int i = 1; i < n * 2 + 1; i++)
	{
		int len = 0;
		while (i - len >= 0 && i + len < n * 2 + 1 && str[i + len] == str[i - len])
			len++;
		len--;
		if (len > maxLen)
		{
			begin = (i - len) / 2;
			maxLen = len;
		}
	}
	return s.substr(begin, maxLen);
}

int main()
{
	std::string s = "babbad";
	std::string ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 75.80%
// memory beats 69.64%
