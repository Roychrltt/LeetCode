#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <functional>
#include <iterator>

std::vector<std::string> f(std::string digits) {
	int n = digits.length();
	if (n == 0) return {};
	std::vector<std::string> ans;
	std::string s(n, 0);
	std::string map[10] = {"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	std::function<void(int)> dfs = [&](int i)
	{
		if (i == n)
		{
			ans.emplace_back(s);
			return;
		}
		for (char c : map[digits[i] - '0'])
		{
			s[i] = c;
			dfs(i + 1);
		}
	};
	dfs(0);
	return ans;
}

int main()
{
	std::vector<std::string> v = f("345");
	std::copy(v.begin(), v.end(), std::ostream_iterator<std::string>(std::cout, " "));
	return 0;
}
// runtime beats 100%
// memory beats 49.73%
