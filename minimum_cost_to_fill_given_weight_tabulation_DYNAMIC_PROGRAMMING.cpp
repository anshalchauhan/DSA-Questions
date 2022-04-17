int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++)
		dp[1][i] = (i/1)*price[0];
	
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int take = -1e9;
			if(i <= j) take = price[i-1] + dp[i][j-i];
			int nottake = dp[i-1][j];
			dp[i][j] = max(take,nottake);
		}
	return dp[n][n];
}