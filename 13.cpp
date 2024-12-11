#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	std::unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
	int total = 0;
	for(size_t i = 0; i < s.size() - 1; i++)
	{
		if(map[s[i]] < map[s[i+1]])
			total -= map[s[i]];
		else
			total += map[s[i]];
	}
	total += map[s.back()];
	return total;
}

int main()
{
	std::string s = "LVIII";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 58.71%
// memory beats 70.60%
