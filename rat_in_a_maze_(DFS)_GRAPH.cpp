class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        int delrow[] = {1,0,0,-1};
        int delcol[] = {0,-1,1,0};
        string direction = "DLRU";
        
        if(m[0][0] == 1)
            dfs(0,0,n,delrow,delcol,direction,visited,m,ans,"");
        
        if(ans.size()) return ans;
        return {"-1"};
    }
    
    void dfs(int row,int col,int n,int delrow[],int delcol[],
    string& direction,vector<vector<int>>& visited,
    vector<vector<int>>& m,vector<string>& ans,string path)
    {
        if(row == n-1 && col == n-1)
        {
            ans.push_back(path);
            return;
        }
            
        for(int k=0;k<4;k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
                
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n 
            && !visited[nrow][ncol] && m[nrow][ncol] == 1)
                {
                    visited[row][col] = 1;
                    dfs(nrow,ncol,n,delrow,delcol,direction,visited,m,ans,path + direction[k]);
                    visited[row][col] = 0;
                }
        }
    }
};