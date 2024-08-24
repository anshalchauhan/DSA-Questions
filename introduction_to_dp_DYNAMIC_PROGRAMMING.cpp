// User function Template for C++

class Solution
{
public:
    long long int mod = pow(10, 9) + 7;
    long long int topDown(int n)
    {
        vector<long long int> memo(n + 1, -1);
        return topDownSolve(n, memo);
    }
    long long int topDownSolve(int n, vector<long long int> &memo)
    {
        if (n <= 1)
            return n;
        if (memo[n] != -1)
            return memo[n];
        return memo[n] = (topDownSolve(n - 1, memo) + topDownSolve(n - 2, memo)) % mod;
    }
    long long int bottomUp(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        long long int prev2 = 0;
        long long int prev1 = 1;
        long long int curr;
        for (int i = 2; i <= n; i++)
        {
            curr = (prev1 + prev2) % mod;
            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }
};