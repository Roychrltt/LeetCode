#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& height) {
	int ans = 0;
	int i = 0, n = height.size() - 1;
	while (i < n)
	{
		ans = std::max(ans, std::min(height[i], height[n]) * (n - i));
		if (height[i] < height[n])
			i++;
		else
			n--;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {1,8,6,2,5,4,8,3,7};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 82.11%
