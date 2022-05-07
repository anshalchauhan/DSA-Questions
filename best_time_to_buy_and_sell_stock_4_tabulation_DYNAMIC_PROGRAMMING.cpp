class Solution {
  public:
    int maxProfit(int k, int n, int p[]) {
        k *= 2;
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        
        for(int i=n-1;i>=0;i--)
            for(int j=k-1;j>=0;j--)
                if(j%2 == 0) dp[i][j] = max(-p[i] + dp[i+1][j+1], dp[i+1][j]);
                else dp[i][j] = max(p[i] + dp[i+1][j+1], dp[i+1][j]);
        return dp[0][0];
    }
};
