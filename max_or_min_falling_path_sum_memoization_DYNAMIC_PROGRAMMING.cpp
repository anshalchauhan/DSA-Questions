int maxsum(int row,int col,vector<vector<int>>& matrix,vector<vector<int>>& hash)
{
	if(col < 0 || col >= matrix[0].size()) return -1e8;
	if(row == 0) return matrix[row][col];
	if(hash[row][col] != -1) return hash[row][col];
	
	int up = matrix[row][col] + maxsum(row-1,col,matrix,hash);
	int upleft = matrix[row][col] + maxsum(row-1,col-1,matrix,hash);
	int upright = matrix[row][col] + maxsum(row-1,col+1,matrix,hash);
	return hash[row][col] = max(up,max(upleft,upright));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
	int row = matrix.size(); 
	int col = matrix[0].size();
	vector<vector<int>> hash(row, vector<int> (col,-1));
	int max1 = -1e8;
	for(int i=0;i<col;i++)
		max1 = max(max1,maxsum(row-1,i,matrix,hash));
	return max1;
}