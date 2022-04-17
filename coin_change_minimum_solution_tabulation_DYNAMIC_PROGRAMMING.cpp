int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
	vector<vector<int>> dp(n, vector<int> (x+1,0));
	
	for(int i=1;i<=x;i++)
	{
		if(i%num[0] == 0) dp[0][i] = i/num[0];
		else dp[0][i] = 1e9;
	}
	
	for(int i=1;i<n;i++)
		for(int j=1;j<=x;j++)
		{	
			int left = 1e9;
			if(num[i]<=j) left = 1 + dp[i][j-num[i]];
			int right = dp[i-1][j];
			dp[i][j] = min(left,right);
		}
	
	if(dp[n-1][x] == 1e9) return -1;
	else return dp[n-1][x];
}