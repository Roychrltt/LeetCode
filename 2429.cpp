#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int minimizeXor(int num1, int num2) {
	int count1 = __builtin_popcount(num1);
	int count2 = __builtin_popcount(num2);
	int ans = num1;
	for (int i = 0; i < 32; i++)
	{
		if (count1 > count2 && (1 << i) & num1)
		{
			count1--;
			ans ^= (1 << i);
		}
		if (count1 < count2 && !((1 << i) & num1))
		{
			count1++;
			ans ^= (1 << i);
		}
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
// memory beats 40.19%
