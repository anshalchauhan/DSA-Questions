int findsum(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& hash)
{
	if(n == 0 && m == 0) return grid[n][m];
	if(n < 0 || m < 0) return 1e9;
	if(hash[n][m] != -1) return hash[n][m];
	int up = grid[n][m] + findsum(n-1,m,grid,hash);
	int left = grid[n][m] + findsum(n,m-1,grid,hash);
	return hash[n][m] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
	int n = grid.size(); 
	int m = grid[0].size();
    vector<vector<int>> hash(n, vector<int> (m,-1));
	return findsum(n-1,m-1,grid,hash);
}