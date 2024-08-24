class Solution
{
public:
    vector<string> all_longest_common_subsequences(string s, string t)
    {
        int n1 = s.size();
        int n2 = t.size();

        // memoization
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        solve(n1, n2, s, t, dp);
        string currentLcs = "";
        set<string> allLcs;
        unordered_map<string, int> umap;
        printLcs(n1, n2, s, t, dp, allLcs, currentLcs, umap);
        vector<string> ans(allLcs.begin(), allLcs.end());
        return ans;
    }

    int solve(int n1, int n2, string &s, string &t, vector<vector<int>> &dp)
    {
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n1][n2];
    }

    void printLcs(int n1, int n2, string &s, string &t, vector<vector<int>> &dp, set<string> &allLcs, string &currentLcs, unordered_map<string, int> &umap)
    {
        if (n1 == 0 || n2 == 0)
        {
            allLcs.insert(currentLcs);
            return;
        }

        string check = to_string(n1) + "," + to_string(n2) + currentLcs;
        if (umap[check])
            return;
        else
            umap[check]++;

        if (s[n1 - 1] == t[n2 - 1])
        {
            currentLcs = s[n1 - 1] + currentLcs;
            printLcs(n1 - 1, n2 - 1, s, t, dp, allLcs, currentLcs, umap);
            currentLcs.erase(currentLcs.begin());
        }

        else
        {
            if (dp[n1 - 1][n2] == dp[n1][n2])
                printLcs(n1 - 1, n2, s, t, dp, allLcs, currentLcs, umap);
            if (dp[n1][n2 - 1] == dp[n1][n2])
                printLcs(n1, n2 - 1, s, t, dp, allLcs, currentLcs, umap);
        }
    }
};