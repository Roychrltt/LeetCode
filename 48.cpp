#include <bits/stdc++.h>

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();
	int top = 0, bot = n - 1;
	while (top < bot)
	{
		for (int i = 0; i < n; i++)
		{
			swap(matrix[top][i], matrix[bot][i]);
		}
		top++;
		bot--;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(matrix[i][j], matrix[j][i]);
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 68.54%
