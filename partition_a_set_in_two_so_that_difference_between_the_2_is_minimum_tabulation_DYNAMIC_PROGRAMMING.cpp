int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	
	vector<vector<bool>> dp(n,vector<bool> (sum+1));
	
	for(int i=0;i<n;i++)
		dp[i][0] = true;
	
	if(arr[0] <= sum) dp[0][arr[0]] = true;
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			bool take = false;
			bool nottake = dp[i-1][j];
			if(arr[i]<=j) take = dp[i-1][j-arr[i]];
			dp[i][j] = take | nottake;
		}
	}
	int min1 = 1e9;
	for(int i=0;i<=sum;i++)
	{
		if(dp[n-1][i])
			min1 = min(min1, abs(sum - 2*i));
	}
	return min1;