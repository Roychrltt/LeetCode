#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::string s, int k)
{
	int count = 0;
	long long sum = 0;
	for (char a : s)
	{
		if (a - '0' > k)
			return -1;
		sum = sum * 10 + (a - '0');
		if (sum > k)
		{
			sum = a - '0';
			count++;
		}
	} 
	return count + 1;
}

int main()
{
	std::string s = "165462";
	int ans = f(s, 60);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 34.87%
