#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int numOfSubarrays(vector<int>& arr, int k, int threshold) {
	int sum = 0, ans = 0;
	for (int i = 0; i < k; i++)
		sum += arr[i];
	if (sum / k >= threshold) ans++;
	int l = 0;
	for (int i = k; i < arr.size(); i++)
	{
		sum += arr[i] - arr[l++];
		if (sum / k >= threshold) ans++;
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
// memory beats 13.40%
