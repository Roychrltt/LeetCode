#include <bits/stdc++.h>

vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
	int n = nums.size();
	unordered_map<int, int> map;
	vector<int> dist(n, INT_MAX), ans;
	for(int i = 0; i < n * 2; ++i){
		if(map.find(nums[i % n]) != map.end()){
			int cur = i % n, prev = map[nums[cur]] % n;
			dist[cur] = min(dist[cur], i - map[nums[cur]]);
			dist[prev] = min(dist[prev], i - map[nums[cur]]);
		}
		map[nums[i % n]] = i;
	}
	for(auto q: queries)
		ans.push_back((dist[q] >= nums.size())? -1 : dist[q]);
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats %
// memory beats %
