int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
	for(int i=weight[0];i<=w;i++)
		dp[0][i] = (i/weight[0])*profit[0];
	
	for(int i=1;i<n;i++)
		for(int j=1;j<=w;j++)
		{
			int take = -1e9;
			if(weight[i] <= j) take = profit[i] + dp[i][j-weight[i]];
			int nottake = dp[i-1][j];
			dp[i][j] = max(take,nottake);
		}
	return dp[n-1][w];
}