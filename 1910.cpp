#include <bits/stdc++.h>

string removeOccurrences(string s, string part) {
	int len = part.length();
	while (s.length() >= len && s.find(part) != string::npos)
		s.erase(s.find(part), len);
	return s;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 52.10%
// memory beats 79.97%
