#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

uint32_t reverseBits(uint32_t n) {
	uint32_t ans = 0;
	for (int i = 0; i < 32; i++)
	{
		uint32_t digit = n & 1;
		ans = (ans << 1) | digit;
		n >>= 1;
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
// runtime beats 35.57%
// memory beats 29.03%
