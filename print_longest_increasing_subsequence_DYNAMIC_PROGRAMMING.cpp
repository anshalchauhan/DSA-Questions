class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> ans;
        
        // tabulation
        vector<int> dp(n,1);
        // store
        vector<int> store(n,0);
        
        int maxi = 0;
        int maxIndex = 0;
        
        for(int i=0;i<n;i++)
        {
            store[i] = i;
            for(int j=0;j<=i;j++)
            {
                if(arr[i] > arr[j] && dp[j] + 1 > dp[i])
                {
                        dp[i] = 1 + dp[j];
                        store[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                maxIndex = i;
            }
        }
        
        while(store[maxIndex] != maxIndex)
        {
            ans.push_back(arr[maxIndex]);    
            maxIndex = store[maxIndex];
        }
        ans.push_back(arr[maxIndex]);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};