#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'X')
		{
			count++;
			i += 2;
		}
	}
	return count;
}

int main()
{
	std::string s = "XXXXOOOOOXOXOOXOOOXOXXOXO";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 17.74%
