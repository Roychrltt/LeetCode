#include <bits/stdc++.h>

int maxChunksToSorted(vector<int>& arr) {
	int n = arr.size();
	vector<int> rightmin(n);
	vector<int> leftmax(n);
	leftmax[0] = arr[0];
	for(int i = 1; i < n; i++)
		leftmax[i] = max(leftmax[i - 1],arr[i]);
	rightmin[n - 1] = arr[n - 1];
	for(int i = n-2; i >= 0; i--)
		rightmin[i] = min(arr[i],rightmin[i + 1]);
	int ans = 1;
	for(int i = 0; i < n - 1; i++)
		if (leftmax[i] <= rightmin[i + 1]) ans++;
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
// memory beats 39.61%
