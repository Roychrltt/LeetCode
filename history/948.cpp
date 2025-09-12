#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

int f(std::vector<int>& tokens, int power) {
	std::sort(tokens.begin(), tokens.end());
	int p = power;
	int score = 0, i = 0, j = tokens.size() - 1;
	while (i <= j && power >= tokens[i]) {
		while (i <= j && power >= tokens[i]) {
			power -= tokens[i++];
			score++;
		}
		if (i < j) {
			power += tokens[j--];
			score--;
		}
	}
	return score;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v,10);
	std::cout << ans << std::endl;
	v = {100,200,300,400};
	ans = f(v,200);
	std::cout << ans << std::endl;
	v = {98,1,6,3,200,5,9,88,42,124,1,654,23,1,1,45,234,543,11};
	ans = f(v,50);
	std::cout << ans << std::endl;
	v = {71,55,82};
	ans = f(v,54);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 100%
// memory beats 19.45%
