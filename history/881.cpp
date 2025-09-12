#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& people, int limit) {
	int ans = 0;
	std::sort(people.begin(), people.end());
	int l = 0, r = people.size() - 1;
	while (l <= r) 
	{
		if (people[l] + people[r] > limit)
			r--;
		else
		{
			l++;
			r--;
		}
		ans++;
	}
	return ans;
}

int main()
{
	std::vector<int> v = {3,2,2,1,4,2,3,2};
	int ans = f(v, 4);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 85.52%
// memory beats 88.76%
