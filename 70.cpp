#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(int n) {
	int ans = 1;
	int prev = 0;
	int cur = 1;
	for (int i = 1; i < n; i++)
	{
		ans += cur;
		int temp = cur;
		cur = cur + prev;
		prev = temp;
	}
	return ans;
}

int main()
{
	int n = 3;
	int ans = f(n);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 24.12%
