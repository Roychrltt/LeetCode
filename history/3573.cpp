#include <bits/stdc++.h>

long long int maximumProfit(vector<int>& prices, int k) {
	int n = prices.size();
	if (n < 2 || k == 0) return 0;

	vector<long long int> dp_prev(n, 0), dp_cur(n, 0);

	for (int t = 1; t <= k; t++) {
		long long int best_buy = -prices[0];   
		long long int best_short = prices[0];      
		dp_cur[0] = 0;

		for (int i = 1; i < n; i++) {
			long long int a = dp_cur[i - 1];                
			long long int b = best_buy + prices[i];         
			long long int c = best_short - prices[i];           

			dp_cur[i] = max({a, b, c});

			best_buy = max(best_buy, dp_prev[i - 1] - prices[i]);
			best_short = max(best_short, dp_prev[i - 1] + prices[i]);
		}
		swap(dp_prev, dp_cur);
	}
	return dp_prev[n - 1];
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
