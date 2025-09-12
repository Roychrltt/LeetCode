#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(int mass, std::vector<int>& a) {
	std::sort(a.begin(), a.end());
	long long s = mass;
	for (const int i: a) {

		if (s < i){
			return false;
		}
		s += i;
	}
	return true;  
}

int main()
{
	std::vector<int> v = {3,9,19,5,21,100};
	int ans = f(10, v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 71.59%
// memory beats 35.34%
