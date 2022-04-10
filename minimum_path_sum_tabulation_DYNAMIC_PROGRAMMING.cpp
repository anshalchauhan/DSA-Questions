class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m);
        for(int i=0;i<n;i++)
        {
            vector<int> dpnext(m);
            for(int j=0;j<m;j++)
            {   
                if(i == 0 && j == 0) dpnext[j] = grid[i][j];
                else
                {
                    int down = 1e4;
                    int right = 1e4;
                    if(i > 0) down = grid[i][j] + dp[j];
                    if(j > 0) right = grid[i][j] + dpnext[j-1];
                    dpnext[j] = min(down,right);
                }
            }
            dp = dpnext;
        }
    return dp[m-1];
    }
};