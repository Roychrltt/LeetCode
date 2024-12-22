#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(int n) {
	int ans = 1;
	int twoPrev = 0;
	int onePrev = 1;
	for (int i = 1; i < n; i++)
	{
		ans += onePrev;
		int temp = onePrev;
		onePrev = onePrev + twoPrev;
		twoPrev = temp;
	}
	return ans;
}

int main()
{
	int n = 5;
	int ans = f(n);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 24.12%
