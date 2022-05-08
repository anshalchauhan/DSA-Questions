class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--)
            for(int j=0;j<=1;j++)
                if(j == 0) dp[i][j] = max(-p[i]+dp[i+1][1],dp[i+1][j]);
                else dp[i][j] = max(p[i]+dp[i+2][0],dp[i+1][j]);
        return dp[0][0];
    }
};