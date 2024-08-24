class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // // memoization
        // vector<vector<int>> dp(N,vector<int> (N,-1));
        // return solve(1,N-1,arr,dp);
        
        // tabulation
        vector<vector<int>> dp(N,vector<int> (N,0));
        int n = N;
        
        for(int i=n-1;i>=1;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                int mini = 1e9;
                for(int k=i;k<j;k++)
                {
                    int total = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j]; 
                    mini = min(total,mini);
                }
        
                dp[i][j] = mini;
            }
        }
        
        return dp[1][n-1];
    }
    
    // // memoization
    // int solve(int i,int j,int arr[],vector<vector<int>>& dp)
    // {
    //     if(i == j) return 0;
    //     if(dp[i][j] != -1)  return dp[i][j];
        
    //     int mini = 1e9;
    //     for(int k=i;k<j;k++)
    //     {
    //         int total = arr[i-1] * arr[k] * arr[j] + solve(i,k,arr,dp) + solve(k+1,j,arr,dp); 
    //         mini = min(total,mini);
    //     }
        
    //     return dp[i][j] = mini;
    // }
};