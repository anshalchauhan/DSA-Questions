class Solution{
public:
    vector<vector<int>> nQueen(int n) {
    vector<vector<int>> ans;
    vector<vector<int>> board(n);
    vector<int> sol;
    vector<int> s(n,0);
    
    for(int i=0;i<n;i++)
        board[i] = s;
        
    nqueen(ans,board,n,0,sol);
    return ans;
    }
    
    bool issafe(vector<vector<int>> board,int n,int row,int col)
    {
        int duprow = row;
        int dupcol = col;
        

        while(row >= 0)
        {
            if(board[row][col] == 1) return false;
            row--;
        }
        
        row = duprow;
        
        while(row >= 0 && col >= 0)
        {
            if(board[row][col] == 1) return false;
            row--;
            col--;
        }
        
        row = duprow;
        col = dupcol;
        
        while(col < n && row >= 0)
        {
            if(board[row][col] == 1) return false;
            row--;
            col++;
        }

        return true;
    }
    
    void nqueen(vector<vector<int>>& ans,vector<vector<int>>& board,int n,int row,vector<int>& sol)
    {
        if(row == n)
        {
            ans.push_back(sol);
            return;
        }
        
        for(int col=0;col<n;col++)
        {
            if(issafe(board,n,row,col))
            {
                sol.push_back(col+1);
                board[row][col] = 1;
                nqueen(ans,board,n,row+1,sol);
                sol.pop_back();
                board[row][col] = 0;
            }
        }
    }
};