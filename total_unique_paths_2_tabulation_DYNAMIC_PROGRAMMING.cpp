class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        
        vector<int> dp(m);
        
        for(int i=0;i<n;i++)
        {
            vector<int> dpnext(m);
            for(int j=0;j<m;j++)
            {
                if(i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) continue;
                
                if(i == 0 && j == 0) dpnext[j] = 1;
                else
                {    
                    int down = 0;
                    int right = 0;
                    if(i > 0) down = dp[j];
                    if(j > 0) right = dpnext[j-1];
                    dpnext[j] = down+right;
                }
            }
            dp = dpnext;
        }
        return dp[m-1];
    }
};