#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
	int s[2] = {0}; 
	int maxS1 = 0;
	for (int i = 0; i < customers.size(); i++) {
		s[grumpy[i]] += customers[i];
		if (i < minutes - 1)
			continue;
		maxS1 = max(maxS1, s[1]);
		if (grumpy[i - minutes + 1])
			s[1] -= customers[i - minutes + 1];
	}
	return s[0] + maxS1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 13.53%
