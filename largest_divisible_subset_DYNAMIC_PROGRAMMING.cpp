class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        // tabulation
        vector<int> dp(n, 1);
        vector<int> hash(n, 0);

        int maxInd = 0;
        int maxi = 0;

        // sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int j = 0; j <= i; j++)
            {
                if (nums[i] % nums[j] == 0 &&
                    nums[i] != nums[j] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if (maxi < dp[i])
            {
                maxi = dp[i];
                maxInd = i;
            }
        }

        while (hash[maxInd] != maxInd)
        {
            ans.push_back(nums[maxInd]);
            maxInd = hash[maxInd];
        }
        ans.push_back(nums[maxInd]);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};