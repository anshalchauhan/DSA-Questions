int knapsack(vector<int> weights, vector<int> values, int n, int w) 
{
	vector<vector<int>> dp(n,vector<int> (w+1,0));
	
	for(int i=weights[0];i<=w;i++)
		dp[0][i] = values[0];

	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			int take = -1e9;
			if(weights[i]<=j) take = values[i] + dp[i-1][j-weights[i]];
			int nottake = dp[i-1][j]; 
			dp[i][j] = max(take,nottake);
		}
	}
	return dp[n-1][w];
}