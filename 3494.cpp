#include <bits/stdc++.h>

long long minTime(std::vector<int>& skill, std::vector<int>& mana) {
	int n = skill.size(), m = mana.size();
	std::vector<long long> done(n + 1);
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i)
			done[i + 1] = std::max(done[i + 1], done[i]) + mana[j] * skill[i];
		std::cout << done[0] << " " << done[1] << " " << done[2] << " " << done[3] << " " << done[4] << std::endl;
		for (int i = n - 1; i > 0; --i)
			done[i] = done[i + 1] - mana[j] * skill[i];
		std::cout << done[0] << " " << done[1] << " " << done[2] << " " << done[3] << " " << done[4] << std::endl;
	}
	return done.back();
}

int main()
{
	std::vector<int> skill = {3, 5, 3, 9};
	std::vector<int> mana = {1, 10, 7, 3};
	long long ans = minTime(skill, mana);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
