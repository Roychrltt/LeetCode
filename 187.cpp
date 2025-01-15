#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

class Solution {
	const int L = 10;
	std::unordered_map<char, int> map = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
	public:
	std::vector<std::string> findRepeatedDnaSequences(std::string s) {
		std::vector<std::string> ans;
		int n = s.length();
		if (n <= L) return ans;
		int x = 0;
		for (int i = 0; i < L - 1; ++i)
			x = (x << 2) | map[s[i]];
		std::unordered_map<int, int> cnt;
		for (int i = 0; i <= n - L; ++i) {
			x = ((x << 2) | map[s[i + L - 1]]) & ((1 << (L * 2)) - 1);
			if (++cnt[x] == 2)
				ans.push_back(s.substr(i, L));
		}
		return ans;
	}
};

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 96.02%
// memory beats 95.04%
