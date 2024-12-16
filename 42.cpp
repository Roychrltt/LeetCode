#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[90m"
# define BOLD "\033[1m"
# define UNDER "\033[4m"
# define BLINK "\033[5m"
# define ERASE = "\033[2K\r"
# define RESET "\033[0m"

int f(std::vector<int>& height) {
	int n = height.size();
	std::vector<int> prefix(n);
	std::vector<int> suffix(n);

	prefix[0] = height[0];
	suffix[n - 1] = height[n - 1];

	for (int i = n - 2; i > -1; i--)
		suffix[i] = std::max(height[i], suffix[i + 1]);

	int sum = 0;
	for (int i = 1; i < n; i++)
	{
		prefix[i] = std::max(height[i], prefix[i - 1]);
		sum += std::min(prefix[i], suffix[i]) - height[i];
	}
	return sum;
}

int main()
{
	std::vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 7.05%
