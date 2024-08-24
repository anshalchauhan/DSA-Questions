class Solution {
  public:
    int minCostClimbingStairs(vector<int>&cost ,int N) {
        vector<int> dp(N+1,-1);
        int ans = solve(cost,N,dp);
        return ans;
    }
    
    int solve(vector<int>& cost, int N,vector<int>& dp)
    {
        if(N == 0 || N == 1) return dp[N] = cost[N];
        if(dp[N] != -1) return dp[N];
        
        int stepCost = 0;
        if(N != cost.size()) stepCost = cost[N];
        
        return dp[N] = min(solve(cost,N-1,dp) + stepCost, solve(cost,N-2,dp) + stepCost);
    }
};