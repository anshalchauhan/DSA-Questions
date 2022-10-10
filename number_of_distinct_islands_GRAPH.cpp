class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        set<vector<pair<int,int>>> set1;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j] == 1 && !visited[i][j])
                    {
                        visited[i][j] = 1;
                        vector<pair<int,int>> vec;
                        bfs(n,m,i,j,grid,visited,vec);
                        set1.insert(vec);
                    }
                    
        return set1.size();
    }
    
    void bfs(int n,int m,int i,int j,
    vector<vector<int>>& grid,vector<vector<int>>& visited,
    vector<pair<int,int>>& vec)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
        pair<int,int> start = {i,j};
        vec.push_back({0,0});
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            int delrow[] = {0,1,0,-1};
            int delcol[] = {1,0,-1,0};
        
            for(int k=0;k<4;k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
            
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    visited[nrow][ncol] = 1;
                    vec.push_back({nrow - start.first, ncol - start.second});
                    q.push({nrow,ncol});
                }
            }
        }
    }
};