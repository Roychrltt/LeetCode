#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

std::vector<std::vector<char>> f(std::vector<std::vector<char>>& box) {
	int row = box.size(); 
	int col = box[0].size(); 
	std::vector<std::vector<char>> ans(col, std::vector<char>(row, '.'));
	for (int i = 0; i < row; i++)
	{
		int j = 0;
		while(j < col)
		{
			int count = 0;
			while (j < col && box[i][j] != '*')
			{
				if (box[i][j] == '#')
					count++;
				j++;
			}
			if (j != col)
				ans[j][row - i - 1] = '*';
			while (count)
			{
				ans[j - count][row - i - 1] = '#';
				count--;
			}
			j++;
		}
	}
	return ans;
}

int main()
{
	std::vector<std::vector<char>> v = {{'#','.','*','.'},{'#','#','*','.'}};
	std::vector<std::vector<char>> ans = f(v);
	for (auto row : ans)
		for (char c : row)
			std::cout << c << std::endl;
	return 0;
}
// runtime beats 90.60%
// memory beats 79.35%
