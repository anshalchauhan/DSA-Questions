// memoization
int solve(vector<int>& arr,int n,int sum,vector<vector<int>>& dp)
{
    if(n == 0)  return abs(sum - 2*arr[n]);
    if(dp[n][sum] != -1)    return dp[n][sum];
    
    int take = INT_MAX;
    if(sum >= 2*arr[n]) take = solve(arr,n-1,sum-2*arr[n],dp); 
    int nottake = solve(arr,n-1,sum,dp);

    return dp[n][sum] = min(take,nottake);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];

    vector<vector<int>> dp(n,vector<int> (sum+1,-1));
    return solve(arr,n-1,sum,dp);
}


// tabulation
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += arr[i];

    vector<vector<int>> dp(n,vector<int> (sum+1,INT_MAX));

    // base cases
    for(int i=0;i<=sum;i++)
        dp[0][i] = abs(i - 2*arr[0]);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            int take = INT_MAX;
            if(j >= 2*arr[i]) take = dp[i-1][j-2*arr[i]];
            int nottake = dp[i-1][j];
            dp[i][j] = min(take,nottake);
        }
    }

    return dp[n-1][sum];
}