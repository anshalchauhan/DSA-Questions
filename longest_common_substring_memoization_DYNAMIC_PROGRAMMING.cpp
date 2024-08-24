class Solution
{
public:
    int longestCommonSubstr(string s1, string s2)
    {
        int n1 = s1.size();
        int n2 = s2.size();
        int len = min(n1, n2);
        // memoization
        vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(len, -1)));
        return solve(n1 - 1, n2 - 1, 0, s1, s2, dp);
    }

    int solve(int n1, int n2, int len, string &s1, string &s2, vector<vector<vector<int>>> &dp)
    {
        if (n1 < 0 || n2 < 0)
            return len;
        if (dp[n1][n2][len] != -1)
            return dp[n1][n2][len];

        int result = len;
        if (s1[n1] == s2[n2])
            result = solve(n1 - 1, n2 - 1, len + 1, s1, s2, dp);

        return dp[n1][n2][len] = max(result, max(solve(n1 - 1, n2, 0, s1, s2, dp), solve(n1, n2 - 1, 0, s1, s2, dp)));
    }
};