int findmin(int n,int m,int i,vector<vector<int>>& triangle,vector<vector<int>>& hash)
{
	if(i == n-1) return triangle[i][m];
	
	if(i < 0 || m < 0) return 0;
	
	if(hash[i][m] != -1) return hash[i][m];
	int down = 1e9;
	int right = 1e9;
	down = triangle[i][m] + findmin(n,m,i+1,triangle,hash);
	right = triangle[i][m] + findmin(n,m+1,i+1,triangle,hash);
	return hash[i][m] = min(right,down);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> hash(n, vector<int> (n,-1));
	return findmin(n,0,0,triangle,hash);
}