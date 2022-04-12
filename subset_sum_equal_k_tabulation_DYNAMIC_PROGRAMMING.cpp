bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int> (k+1,0));
	
	for(int i=0;i<n;i++) dp[i][0] = 1;
	if(arr[0]<=k) dp[0][arr[0]] = 1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			int left = 0;
			if(arr[i] <= j) left = dp[i-1][j-arr[i]];
			int right = dp[i-1][j];
			dp[i][j] = left+right;
		}
	}
	return dp[n-1][k];
}