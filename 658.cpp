#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
	int n = arr.size();
	if (n == k) return arr;
	int l = std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
	if (l > 0) l--;
	int r = l + 1;
	int i = 0;
	while (i < k)
	{
		if ((l > -1 && r < n && std::abs(arr[l] - x) <= std::abs(arr[r] - x)) || r == n)
			l--;
		else
			r++;
		i++;
	}
	return std::vector<int>(arr.begin() + l + 1, arr.begin() + l + k + 1);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 65.35%
