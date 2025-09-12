#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string reverseWords(std::string s) {
	std::stringstream ss(s);
	std::string word;
	std::string ans;
	while (ss >> word)
	{
		std::reverse(word.begin(), word.end());
		ans += word + " ";
	}
	return ans.substr(0, ans.length() - 1);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 18.13%
