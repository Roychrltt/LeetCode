#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimumRecolors(std::string blocks, int k) {
	int W = 0;
	for (int i = 0; i < k; ++i)
		W += blocks[i] & 1;
	int ans = W;
	for (int i = k; i < blocks.length(); ++i) {
		W += (blocks[i] & 1) - (blocks[i - k] & 1);
		ans = min(ans, W);
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
// memory beats 36.18%
