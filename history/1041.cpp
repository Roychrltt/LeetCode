#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

bool isRobotBounded(string instructions) {
	int direction = 0, x = 0, y = 0;
	for (char c : instructions)
	{
		if (c == 'R') direction = (direction + 1) % 4;
		else if (c == 'L') direction = (direction + 3) % 4;
		else
		{
			if (direction == 0) ++y;
			else if (direction == 1) ++x;
			else if (direction == 2) --y;
			else --x;
		}
	}
	return (x == 0 && y == 0) || direction != 0;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 36.87%
