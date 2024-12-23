#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
	std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
	int maxLen = std::ranges::max(wordDict, {}, &std::string::length).length();

	int n = s.length();
	std::vector<bool> f(n + 1);
	f[0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i - 1; j >= std::max(i - maxLen, 0); j--)
		{
			if (f[j] && words.count(s.substr(j, i - j)))
			{
				f[i] = true;
				break;
			}
		}
	}
	return f[n];
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 87.74%
