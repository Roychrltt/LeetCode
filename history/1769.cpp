#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> minOperations(std::string boxes) {
	int n = boxes.size();
	std::vector<int> ans(n);
	int t = 0, s = 0;
	for (int i = 0; i < n; ++i) {
		ans[i] += s;
		if (boxes[i] == '1') ++t;
		s += t;
	}
	t = 0;
	s = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans[i] += s;
		if (boxes[i] == '1') ++t;
		s += t;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 67.01%
