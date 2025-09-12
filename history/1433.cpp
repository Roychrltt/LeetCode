#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::string s1, std::string s2) {
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	int x = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		int c = 0;
		if (s1[i] > s2[i])
			c = 1;
		else if (s1[i] < s2[i])
			c = -1;
		if (x == 0)
			x = c;
		if (x != 0 && x != c && c != 0)
			return false;
	}
	return true;
}

int main()
{
	std::string s1 = "yopumzgd";
	std::string s2 = "pamntyya";
	bool ans = f(s1, s2);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 78.79%
// memory beats 22.68%
