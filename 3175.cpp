#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int findWinningPlayer(std::vector<int>& skills, int k) {
	int count = 1;
	int index = skills[0] > skills[1] ? 0 : 1;
	if (k == 1) return index;
	for (int i = 2; i < skills.size(); i++)
	{
		if (skills[i] < skills[index])
			count++;
		else
		{
			count = 1;
			index = i;
		}
		if (count == k) return index;
	}
	return index;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 54.03%
