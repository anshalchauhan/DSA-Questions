class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    
    vector<vector<string>> ans;
	vector<string> board(n);
	string s(n,'.');

	for(int i=0;i<n;i++)
	 	board[i] = s;

	nqueen(ans,board,n,0);
    
    return ans;
    }
    
   bool issafe(vector<string> board,int n,int row,int col)
   {
	int duprow = row;
	int dupcol = col;

	while(row >= 0)
	{
		if(board[row][col] == 'Q') return false;
		row--;
	}

	row = duprow;

	while(row >= 0 && col >= 0)
	{
		if(board[row][col] == 'Q') return false;
		row--;
		col--;
	}

	row = duprow;
	col = dupcol;

	while(col < n && row >= 0)
	{
		if(board[row][col] == 'Q') return false;
		row--;
		col++;
	}
 
   return true;
    }
    
   void nqueen(vector<vector<string>>& ans,vector<string>& board,int n,int row)
   {
	if(row == n)
	{
		ans.push_back(board);
		return;
	}

	for(int col=0;col<n;col++)
	{
		if(issafe(board,n,row,col))
		{
			board[row][col] = 'Q';
			nqueen(ans,board,n,row+1);
			board[row][col] = '.';
		}
	}
   }

};