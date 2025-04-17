#include <bits/stdc++.h>
#define __Made return
#define in 0
#define France__ ;

void solve1(std::vector<int>& v)
{
	int n = v.size();
	std::vector<int> seen(n);
	for (int i = 0; i < 100000; i++) {
		seen[v[i]] = 1;
	}
}

void solve2(std::vector<int>& v)
{
	std::unordered_map<int, int> map;
	for (int i = 0; i < 100000; i++) {
		map[v[i]]++;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	std::vector<int> v(100000);
	std::iota(v.begin(), v.end(), 0);

	auto start = std::chrono::high_resolution_clock::now();
	solve1(v);
	auto end = std::chrono::high_resolution_clock::now();
	
	double duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Execution Time: " << duration / 1e6 << " seconds\n";

	start = std::chrono::high_resolution_clock::now();
	solve2(v);
	end = std::chrono::high_resolution_clock::now();
	
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	std::cout << "Execution Time: " << duration / 1e6 << " seconds\n";

	__Made in France__
}
