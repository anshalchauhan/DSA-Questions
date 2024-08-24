class Solution
{
public:
    static bool comp(const string &a, const string &b)
    {
        return a.size() < b.size();
    }

    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);

        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                if (compare(words[i], words[j]) && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

    bool compare(string &a, string &b)
    {
        if (a.size() != b.size() + 1)
            return false;
        int n = 0;
        int m = 0;

        while (n < a.size())
        {
            if (a[n] == b[m])
            {
                n++;
                m++;
            }
            else
                n++;
        }

        if (n == a.size() && m == b.size())
            return true;
        return false;
    }
};