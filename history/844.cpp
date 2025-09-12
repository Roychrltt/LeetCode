#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	std::string build(std::string str) {
		std::string ans;
		for (char c : str) {
			if (c != '#')
				ans.push_back(c);
			else if (!ans.empty())
				ans.pop_back();
		}
		return ans;
	}
	public:
	bool backspaceCompare(std::string s, std::string t) {
		return build(s) == build(t);
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 23.68%
