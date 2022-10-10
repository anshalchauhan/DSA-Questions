class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //traverse the first and last rows
        for(int j=0;j<m;j++)
        {
            if(grid[0][j] == 1 && !visited[0][j])
                dfs(n,m,0,j,grid,visited);
            if(grid[n-1][j] == 1 && !visited[n-1][j])
                dfs(n,m,n-1,j,grid,visited);
        }
        
        //traverse the first and last columns
        for(int i=1;i<n-1;i++)
        {
            if(grid[i][0] == 1 && !visited[i][0])
                dfs(n,m,i,0,grid,visited);
            if(grid[i][m-1] == 1 && !visited[i][m-1])
                dfs(n,m,i,m-1,grid,visited);
        }
        
        for(int i=1;i<n-1;i++)
            for(int j=1;j<m-1;j++)
                if(grid[i][j] == 1 && !visited[i][j]) count++;
        
        return count;
    }
    
    void dfs(int n,int m,int row,int col,
    vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        int delrow[] = {0,1,-1,0};
        int delcol[] = {1,0,0,-1};
        
        for(int k=0;k<4;k++)
        {
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            
            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
            && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                visited[nrow][ncol] = 1;
                dfs(n,m,nrow,ncol,grid,visited);
            }
        }
    }
};