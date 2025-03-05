#include <bits/stdc++.h>

vector<int> pivotArray(vector<int>& nums, int pivot) {
	int n = nums.size();
	vector<int> v(n);
	int count(0), j(0);
	for (int x : nums)
	{
		if (x < pivot)
		{
			v[j] = x;
			j++;
		}
		else if (x == pivot) count++;
	}
	while (count--)
		v[j++] = pivot;
	for (int x : nums)
		if (x > pivot)
			v[j++] = x;
	return v;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 96.88%
