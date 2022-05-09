class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size();
        int max1 = 1;
        vector<int> dp(n,1), count(n,1);
  
        for(int i=1;i<n;i++) {
            for(int prev=0; prev<i; prev++)
            {
                if(a[i] > a[prev] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    count[i] = count[prev];   
                }
                
                else if(a[i] > a[prev] && 1 + dp[prev] == dp[i] )
                    count[i] += count[prev];
            }
			max1 = max(max1,dp[i]);
		}
	
		int total = 0;
		for(int i=0;i<n;i++)
			if(dp[i] == max1) total += count[i];
			
    return total;
    }
};