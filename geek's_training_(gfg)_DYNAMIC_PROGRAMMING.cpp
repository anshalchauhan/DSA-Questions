class Solution {
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>> dp(n, vector<int> (4,0)); // dp array
    
        // base cases
        dp[0][0] = max(points[0][1],points[0][2]);
        dp[0][1] = max(points[0][0],points[0][2]);
        dp[0][2] = max(points[0][0],points[0][1]);
        dp[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
        
        for(int day=1;day<n;day++)
        {
            for(int last=0;last<4;last++)
            {
                dp[day][last] = 0;
                int maximum = 0;
                
                for(int ind=0;ind<3;ind++)
                    if(ind != last)
                    {
                        maximum = max(maximum, points[day][ind] + dp[day-1][ind]);
                    }
                    
                dp[day][last] = maximum;
            }
        }
        
        return dp[n-1][3];
    }
    
    // memoization
    // int solve(int n,int last,vector<vector<int>>& points,vector<vector<int>>& dp)
    // {
    //     if(n < 0)   return 0;
    //     if(dp[n][last] != -1)   return dp[n][last];
        
    //     int maximum = 0;
    //     for(int i=0;i<3;i++)
    //         if(i != last)
    //             maximum = max(maximum, solve(n-1,i,points,dp) + points[n][i]);
        
    //     return dp[n][last] = maximum;
    // }
};