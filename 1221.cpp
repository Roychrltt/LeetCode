#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s) {
	int count = 0, score = 0;
	for (const auto& c : s) {
		score += c == 'L' ? 1 : -1;
		if (score == 0)
			count++;
	}
	return count;
}

int main()
{
	std::string s = "RLRRLLRLRL";
	int ans = f(s);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 22.30%
