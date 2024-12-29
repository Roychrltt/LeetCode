#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string answerString(std::string word, int numFriends) {
	if (numFriends == 1) return word;
	int n = word.length();
	int len = n - numFriends + 1;
	std::string ans = word.substr(0, len);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < len && i + j < n; j++)
		{
			if (word[i + j] < ans[j]) break;
			if (word[i + j] > ans[j])
				ans = word.substr(i, std::min(len, n - i));
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
// runtime beats 61.54%
// memory beats 76.92%
