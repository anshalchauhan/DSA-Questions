class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        
        for(int i=0;i<n;i++)
            dp[i] = triangle[n-1][i];
        
        for(int i=n-2;i>=0;i--)
        {
            vector<int> dpnext(n);
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j] + dp[j+1];
                int dia = triangle[i][j] + dp[j];
                dpnext[j] = min(down,dia);
            }
            dp = dpnext;
        }
        return dp[0];
    }
};