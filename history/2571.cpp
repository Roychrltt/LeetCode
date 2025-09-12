#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(int n) {
	int count = 0;
	while (n > 0) {
		if ((n & 3) == 3)
		{
			n++;
			count++;
		}
		else
		{
			count += n & 1;
			n >>= 1;
		}
	}
	return count;
}

int main()
{
	int ans = f(109);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 31.71%
