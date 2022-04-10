int allpaths(int m,int n,vector<vector<int>>& hash)
{
	if(m == 0 && n == 0) return 1;
	if(m < 0 || n < 0) return 0;
	if(hash[m][n] != -1) return hash[m][n];
	int up = allpaths(m-1,n,hash);
	int left = allpaths(m,n-1,hash);
	return hash[m][n] = up + left;
}
int uniquePaths(int m, int n) {
	vector<vector<int>> hash(m, vector<int> (n,-1));
	return allpaths(m-1,n-1,hash);
}