#include<bits/stdc++.h>
long getMaximumProfit(long *v, int n)
{
    vector<vector<long>> dp(n+1, vector<long>(2,0));
	
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<2;j++)
		{
			long profit = 0;
			if(j)
				profit = max(-v[i] + dp[i+1][0], dp[i+1][j]);
			else
				profit = max(v[i] + dp[i+1][1], dp[i+1][j]);
			dp[i][j] = profit;
		}
	
	return dp[0][1];
}