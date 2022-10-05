class Solution {
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size(), m = grid[0].size();
        
        vector<vector<int>> visited(grid.size(),vector<int> (grid[0].size(),0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == '1' && !visited[i][j])
                    {
                        ans++;
                        bfs(i,j,n,m,grid,visited,ans);
                    }
                    
        return ans;
    }
    
    void bfs(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& visited,int &ans)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            auto a = q.front();
            q.pop();
            int row = a.first;
            int col = a.second;
            
            for(int delrow = row-1; delrow <= row+1; delrow++)
                for(int delcol = col-1; delcol <= col+1; delcol++)
                    if(delrow > -1 && delrow < n && delcol > -1 && delcol < m)
                        if(grid[delrow][delcol] == '1' && !visited[delrow][delcol])
                        {
                            visited[delrow][delcol] = 1;
                            q.push({delrow,delcol});
                        }
        }
    }
};