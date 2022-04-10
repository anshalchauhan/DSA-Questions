int mazerunner(int n,int m,vector<vector<int>>& mat,vector<vector<int>>& hash)
{
	if(n >= 0 && m >= 0 && mat[n][m] == -1) return 0;
	if(n == 0 && m == 0) return 1;
	if(n < 0 || m < 0) return 0;
	if(hash[n][m] != -1) return hash[n][m];
	int up = mazerunner(n-1,m,mat,hash);
	int left = mazerunner(n,m-1,mat,hash);
	return hash[n][m] = (up+left)%1000000007;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat) {
	vector<vector<int>> hash(n, vector<int> (m,-1));
    return mazerunner(n-1,m-1,mat,hash);
}