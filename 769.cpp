#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& arr)
{
	int ans = 1, x = arr[0], n = arr.size();
	for (int i = 0; i < n; i++) {
		if (arr[i] > x && arr[i] <= i) {
			x = arr[i];
			ans++;
		}
		std::cout << "x: " << x << std::endl;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {0,3,1,2};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
