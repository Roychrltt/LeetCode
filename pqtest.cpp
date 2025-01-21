#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <numeric>
#include <functional>

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

int main()
{
	std::cout << GREEN << "----------Simple Priority Queue Test with ints----------" << RESET << std::endl;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(1);
	pq.push(3);
	pq.push(8);
	pq.push(2);
	pq.push(9);
	pq.push(16);
	while (!pq.empty())
	{
		std::cout << pq.top() << std::endl;
		pq.pop();
	}
	std::cout << std::endl;
	std::cout << GREEN << "----------Advanced Priority Queue Test with pairs----------" << RESET << std::endl;
	auto cmp = [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first * a.second > b.first * b.second;
    };
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> apq(cmp);
	apq.emplace(1, 2);
	apq.emplace(3, 9);
	apq.emplace(2, 3);
	apq.emplace(7, 1);
	apq.emplace(4, 6);
	apq.emplace(8, 2);
	while (!apq.empty())
	{
		std::cout << apq.top().first << " " << apq.top().second << std::endl;
		apq.pop();
	}
	return 0;
}
