#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool f(std::string& start, std::string& target) {
	int waitL = 0;
	int waitR = 0;

	for (int i = 0; i < start.length(); i++) {
		char curr = start[i];
		char goal = target[i];
		if (curr == 'R') {
			if (waitL > 0)
				return false;
			waitR++;
		}
		if (goal == 'L') {
			if (waitR > 0)
				return false;
			waitL++;
		}
		if (goal == 'R') {
			if (waitR == 0)
				return false;
			waitR--;
		}
		if (curr == 'L') {
			if (waitL == 0)
				return false;
			waitL--;
		}
	}
	return waitL == 0 && waitR == 0;
}

int main()
{
	std::string	s1 = "_L__R__R_";
	std::string	s2 = "__LR__R";
	bool		ans = f(s1, s2);
	std::cout << std::boolalpha << ans << std::endl;
	return 0;
}
// runtime beats 95.50%
// memory beats 79.62%
