#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& players, std::vector<int>& trainers) {
	std::sort(players.begin(), players.end());
	std::sort(trainers.begin(), trainers.end());
	int m = players.size(), n = trainers.size();
	int count = 0;
	int i = 0;
	for (int x : trainers) {
		if (i < m && players[i] <= x) {
			i++;
			count++;
		}
	}
	return count;
}

int main()
{
	std::vector<int> v1 = {4,7,9};
	std::vector<int> v2 = {8,2,5,8};
	int ans = f(v1, v2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 61.56%
// memory beats 73.82%
