class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        sort(cuts.begin(),cuts.end());

        // memoization
        vector<vector<int>> dp(m,vector<int> (m,-1));
        return solve(0,n,0,m-1,cuts,dp);
    }

    int solve(int start,int end,int i,int j,vector<int>& cuts,vector<vector<int>>& dp)
    {
        if(i > j) return 0;
        if(dp[i][j] != -1)  return dp[i][j];

        int mini = 1e9;
        for(int k=i;k<=j;k++)
        {
            int total = end - start + solve(start,cuts[k],i,k-1,cuts,dp) + solve(cuts[k],end,k+1,j,cuts,dp);
            mini = min(mini,total);
        }

        return dp[i][j] = mini;
    }
};