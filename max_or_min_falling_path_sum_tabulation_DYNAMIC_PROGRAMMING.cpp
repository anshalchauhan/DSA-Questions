class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int min1 = 1e4;
        vector<vector<int>> dp(row, vector<int> (row));
        
        for(int i=0;i<row;i++)
        {
            min1 = 1e4;
            for(int j=0;j<row;j++)
            {
                if(i == 0) 
                {
                    dp[i][j] = matrix[i][j];
                    min1 = min(min1,dp[i][j]);
                }
                else
                {
                    int down = matrix[i][j] + dp[i-1][j];
                    int downleft = matrix[i][j];
                    int downright = matrix[i][j];
                    
                    if(j > 0) downleft += dp[i-1][j-1];
                    else downleft += 1e4;
                    if(j < row-1) downright += dp[i-1][j+1];
                    else downright += 1e4;
                    
                    dp[i][j] = min(down,min(downleft,downright));
                    min1 = min(min1,dp[i][j]);
                }
            }
        }
        return min1;
    }
};