class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(n,vector<char>(m,'X'));
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //traverse first and last rows
        for(int j=0;j<m;j++)
        {
            if(mat[0][j] == 'O' && !visited[0][j])
            {
                visited[0][j] = 1;
                ans[0][j] = 'O';
                bfs(n,m,0,j,mat,visited,ans);
            }
            if(mat[n-1][j] == 'O' && !visited[n-1][j])
            {
                visited[n-1][j] = 1;
                ans[n-1][j] = 'O';
                bfs(n,m,n-1,j,mat,visited,ans);
            }
        }
        
        //traverse first and last column
        for(int i=1;i<n-1;i++)
        {
            if(mat[i][0] == 'O' && !visited[i][0])
            {
                visited[i][0] = 1;
                ans[i][0] = 'O';
                bfs(n,m,i,0,mat,visited,ans);
            }
            if(mat[i][m-1] == 'O' && !visited[i][m-1])
            {
                visited[i][m-1] = 1;
                ans[i][m-1] = 'O';
                bfs(n,m,i,m-1,mat,visited,ans);
            }
        }
        
        return ans;
    }
    
    void bfs(int n,int m,int i,int j,vector<vector<char>>& mat,
    vector<vector<int>>& visited,vector<vector<char>>& ans)
    {
        queue<pair<int,int>> q;
        q.push({i,j});
    
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
     
            
            for(int k=0;k<4;k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !visited[nrow][ncol] && mat[nrow][ncol] == 'O')
                {
                    ans[nrow][ncol] = 'O';
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
};