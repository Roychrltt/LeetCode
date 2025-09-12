#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int leastInterval(vector<char>& tasks, int n) {
	int size = tasks.size();
	std::vector<int> v(26);
	int occurMax = 0;
	for(char c : tasks) 
		if (++v[c - 'A'] > occurMax)
			occurMax = v[c - 'A'];            

	int maxTask = 0;
	for (int x : v)
		if (x == occurMax)
			maxTask++;
	return std::max(size, maxTask + (n + 1) * (occurMax - 1));
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 85.78%
