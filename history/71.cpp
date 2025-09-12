#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string simplifyPath(std::string path) {
	std::vector<std::string> v;
	std::stringstream ss(path);
	std::string cur;
	while (std::getline(ss, cur, '/'))
	{
		if (cur == "" || cur == ".") continue;

		if (cur == "..")
		{
			if (!v.empty())
				v.pop_back();
		}
		else
			v.push_back(cur);
	}

	std::stringstream ans;
	for (const auto& s : v) {
		ans << "/" << s;
	}

	return ans.str().empty() ? "/" : ans.str();        
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 62.22%
