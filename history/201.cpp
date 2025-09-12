#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int rangeBitwiseAnd(int left, int right) {
	if (!(left & right)) return 0;
	int ans = 0;
	for (int i = 31; i >= 0; i--)
	{
		if ((left & (1 << i)) != (right & (1 << i))) break;
		if (left & (1 << i)) ans += (1 << i);
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
// memory beats 10.81%
