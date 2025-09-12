#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::string> stringMatching(std::vector<std::string>& words) {
	int n = words.size();
	std::vector<std::string> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && words[j].find(words[i]) != std::string::npos) {
				ans.push_back(words[i]);
				break;
			}
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
// runtime beats 100%
// memory beats 60.52%
