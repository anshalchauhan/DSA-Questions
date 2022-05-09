class Solution{
	public:
	int maxSumIS(int a[], int n)  
	{  
	    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
	    
	    for(int i=n-1;i>=0;i--)
	        for(int j=i-1;j>=-1;j--)
	        {
	            int sum = dp[i+1][j+1];
	            if(j == -1 || a[i] > a[j]) 
	                sum = max(sum,a[i] + dp[i+1][i+1]);
	            dp[i][j+1] = sum;
	        }
	        
	    return dp[0][0];
	}  
};