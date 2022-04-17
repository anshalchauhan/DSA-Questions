int mod = (int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
   	int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	if(sum-d < 0 || (sum-d)%2 ) return 0;
	sum = (sum-d)/2; 

	vector<int> dp(sum+1,0);
	
	
	if(arr[0] == 0) dp[0] = 2;
	else dp[0] = 1;
	
	if(arr[0] != 0 && arr[0] <= sum) dp[arr[0]] = 1;
		
	for(int i=1;i<n;i++)
	{
		vector<int> dpnext(sum+1,0);
		for(int j=0;j<=sum;j++)
		{
			int take = 0;
			if(arr[i] <= j) take = dp[j-arr[i]];
			int nottake = dp[j];
			dpnext[j] = (take + nottake) % mod;
		}
	dp = dpnext;
	}
	return dp[sum];
}
