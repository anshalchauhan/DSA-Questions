int LCS(string s1, string s2, string s3, int m, int n, int o)
{
	vector<vector<vector<int>>> dp(m+1,vector<vector<int>> (n+1,vector<int>(o+1,0)));
	
	for(int i=1;i<=m;i++)
	for(int j=1;j<=n;j++)
	for(int k=1;k<=o;k++)
	{
		if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1])
			dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
		else
			dp[i][j][k] = max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
	}
	return dp[m][n][o];
}