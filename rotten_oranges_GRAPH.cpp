class Orange
{
    public:
    int row;
    int col;
    int rot_time;
    Orange(int row,int col,int rot_time)
    {
        this->row = row;
        this->col = col;
        this->rot_time = rot_time;
    }
};

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int count = 0;
        int fcount = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<Orange*> q;
        Orange* org;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                {
                    if(grid[i][j] == 2)
                    {
                        visited[i][j] = 1;
                        org = new Orange(i,j,0);
                        q.push(org);
                    }
                    
                    if(grid[i][j] == 1)
                        fcount++;
                }
                
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            org = q.front();
            int row = org->row;
            int col = org->col;
            int rot_time = org->rot_time;
            ans = max(ans,rot_time);
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
            
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !visited[nrow][ncol])
                {
                    count++;
                    visited[nrow][ncol] = 1;
                    org = new Orange(nrow,ncol,rot_time+1);
                    q.push(org);
                }
            }      
        }
        
        if(count != fcount) return -1;
        return ans;
    }
};