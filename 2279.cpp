#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& capacity, std::vector<int>& rocks, int additionalRocks) {
	for (int i = 0; i < capacity.size(); i++)
		capacity[i] -= rocks[i];

	std::ranges::sort(capacity);

	int i = 0;

	while (i < capacity.size() && additionalRocks >= capacity[i])
	{
		additionalRocks -= capacity[i];
		i++;
	}    

	return i; 
}

int main()
{
	std::vector<int> v = {2,3,4,5};
	std::vector<int> vv = {1,2,4,4};
	int ans = f(v, vv, 2);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 79.56%
// memory beats 98.16%
