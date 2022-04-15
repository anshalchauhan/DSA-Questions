class Solution {
  public:
    long long int count(int S[], int m, int n) {
        vector<vector<long long int>> dp(m, vector<long long int> (n+1,0));
       
        for(int i=0;i<m;i++)
            dp[i][0] = 1;
            
        for(int i=0;i<=n;i++)
             dp[0][i] = (i%S[0] == 0);
        
        for(long long int i=1;i<m;i++)
            for(long long int j=1;j<=n;j++) {
                    long long int left = 0;
                    if(S[i] <= j) left = dp[i][j-S[i]];
                    long long int right = dp[i-1][j];
                    dp[i][j] = left+right; }
                    
    return dp[m-1][n];
    }
};