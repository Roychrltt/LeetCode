#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool canBeValid(std::string s, std::string locked) {
	int n = s.length();
	if (n % 2) return false;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (locked[i] == '0' || s[i] == '(')
			count++;
		else
			count--;
		if (count < 0) return false;
	}
	count = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (locked[i] == '0' || s[i] == ')')
			count++;
		else
			count--;
		if (count < 0) return false;
	}
	return true;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 95.69%
// memory beats 79.70%
