#include <bits/stdc++.h>

vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
	unordered_map<string,vector<string>> inToRe;
	unordered_map<string,int> inDegree;
	int n = recipes.size();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < ingredients[i].size(); j++)
		{
			inToRe[ingredients[i][j]].push_back(recipes[i]);
			inDegree[recipes[i]]++;
		}
	}
	queue<string> q;
	for(auto s :supplies)
		q.push(s);

	vector<string> ans;
	while(!q.empty()){
		string s = q.front();
		q.pop();
		for(auto& r : inToRe[s]){
			if(--inDegree[r] == 0){
				q.push(r);
				ans.push_back(r);
			}
		}
	}
	return ans;
}

int main()
{
	std::vector<int> v = {};
	int ans = f(v);
	std::cout << ans << std::endl;
	return 0;
}
// runtime beats 53.51%
// memory beats 37.89%
