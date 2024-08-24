class Solution
{
public:
    int minimizeCost(vector<int> &height, int n, int k)
    {
        vector<int> dp(n, -1);
        return solve(height, n - 1, k, dp);
    }

    int solve(vector<int> &height, int n, int k, vector<int> &dp)
    {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];

        int minimum = INT_MAX;
        for (int i = 1; i <= k; i++)
            if (n - i >= 0)
                minimum = min(minimum, abs(height[n] - height[n - i]) + solve(height, n - i, k, dp));

        return dp[n] = minimum;
    }
};