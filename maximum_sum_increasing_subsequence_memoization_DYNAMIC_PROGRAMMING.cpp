class Solution{
	public:
	int maxSumIS(int a[], int n)  
	{  
	    vector<vector<int>> dp(n,vector<int>(n,-1));
	    return findmax(n,a,0,-1,dp);
	}  
	
	int findmax(int n,int a[],int i,int prev,vector<vector<int>>& dp)
	{
        if(i == n) return 0;
        if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        int take = 0;
        if(prev == -1 || a[i] > a[prev]) take = a[i] + findmax(n,a,i+1,i,dp);
        int nottake = findmax(n,a,i+1,prev,dp);
        return dp[i][prev + 1] = max(take,nottake);
	}
};