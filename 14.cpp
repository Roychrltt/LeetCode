#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string f(std::vector<std::string>& strs) {
	std::sort(strs.begin(), strs.end()); 
	std::string first = strs[0];
	std::string last = strs[strs.size() - 1];
	int count = 0;
	for (int i = 0; i < std::min(first.length(), last.length()); ++i)
	{
		if (first[i] != last[i])
			break;        
		count++;
	}
	std::string ans = first.substr(0, count);
	return ans;
}

int main()
{
	std::vector<std::string> v = {"flower", "floor", "foot", "fate", "fantastic"};
	std::string ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 62.03%
