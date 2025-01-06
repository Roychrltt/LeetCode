#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts) {
	std::vector<int> diff(s.length() + 1);
	for (auto& v : shifts) {
		int d = v[2] == 1 ? 1 : 25;
		diff[v[0]] += d;
		diff[v[1] + 1] -= d;
	}
	int d = 0;
	for (int i = 0; i < s.length(); ++i) {
		d += diff[i];
		s[i] = (s[i] + d - 'a') % 26 + 'a';
	}
	return s;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 70.54%
