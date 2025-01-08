#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int countPrefixSuffixPairs(std::vector<std::string>& words) {
	int ans = 0;
	for (int i = 0; i < words.size(); i++)
	{
		for (int j = i + 1; j < words.size(); j++)
		{
			if (words[j].find(words[i]) == 0 && (words[j].rfind(words[i]) + words[i].length() == words[j].length()))
				ans++;
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 76.69%
// memory beats 97.46%
