#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool canConstruct(std::string s, int k) {
	if (s.length() < k) return false;
	std::vector<int> v(26, 0);
	for (char c : s)
		v[c - 'a']++;
	int check = 0;
	for (int i = 0; i < 26; i++)
	{
		if (v[i] % 2== 1) check++;
		if (check > k) return false;
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
// runtime beats 100%
// memory beats 66.78%
