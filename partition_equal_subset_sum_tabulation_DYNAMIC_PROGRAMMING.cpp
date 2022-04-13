class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i=0;i<n;i++)
            sum += nums[i];
        
        if(sum%2 != 0) return 0;
        
        sum = sum/2;
        
        vector<vector<bool>> dp(n, vector<bool> (sum+1,0));
        
        for(int i=0;i<n;i++)
            dp[i][0] = true;
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                bool take = false;
                if(nums[i]<=j)
                    take = dp[i-1][j-nums[i]];
                bool nottake = dp[i-1][j]; 
                dp[i][j] = take|nottake;
            }
        }
    return dp[n-1][sum];
    }
};