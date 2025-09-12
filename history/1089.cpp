#include <bits/stdc++.h>

void duplicateZeros(vector<int>& arr) {
	int n = arr.size();
	int i = 0, j = 0;
	while (j < n)
	{
		if (arr[i] == 0) j++;
		i++;
		j++;
	}
	i--;
	j--;
	while (i >= 0)
	{
		if (j < n) arr[j] = arr[i];
		if (arr[i] == 0 && --j >= 0) arr[j] = 0;
		i--;
		j--;
	}
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 87.09%
