#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string reverseWords(std::string s) {
	std::stringstream ss(s);
	std::string word;
	std::vector<std::string> words;

	while (ss >> word) {
		words.push_back(word);
	}

	std::string ans;
	for (int i = words.size() - 1; i >= 0; i--) {
		ans += words[i];
		if (i != 0) {
			ans += " ";
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
// runtime beats %
// memory beats %
