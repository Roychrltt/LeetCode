#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
	int minBalance = 0;
	int index = 0;
	int balance = 0;
	for (int i = 0; i < gas.size(); i++)
	{
		balance += gas[i] - cost[i];
		if (balance < minBalance)
		{
			minBalance = balance;
			index = i + 1;
		}
	}
	return balance >= 0 ? index : -1;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 13.37%
