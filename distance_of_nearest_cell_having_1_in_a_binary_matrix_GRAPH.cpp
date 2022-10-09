class Cell
{
    public:
    int row;
    int col;
    int distance;
    Cell(int row,int col,int distance)
    {
        this->row = row;
        this->col = col;
        this->distance = distance;
    }
};

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>> nearest(vector<vector<int>> grid)
	{
	    int n = grid.size();
	    int m = grid[0].size();
	    vector<vector<int>> ans(n,vector<int>(m,0));
	    vector<vector<int>> visited(n,vector<int>(m,0));
	    queue<Cell*> q;
	    Cell* node;
	    
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++)
	            if(grid[i][j] == 1)
	                {
	                    node = new Cell(i,j,0);
	                    q.push(node);
	                    visited[i][j] = 1;
	                }
	                
	                
	    while(!q.empty())
	    {
	        node = q.front();
	        q.pop();
	        
	        int row = node->row;
	        int col = node->col;
	        int distance = node->distance;
	        
	        int delrow[] = {-1,0,1,0};
	        int delcol[] = {0,1,0,-1};
	        
	        for(int k=0;k<4;k++)
	        {
	            int nrow = row + delrow[k];
	            int ncol = col + delcol[k];
	            
	            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
	                grid[nrow][ncol] == 0 && !visited[nrow][ncol])
	                {
	                    visited[nrow][ncol] = 1;
	                    node = new Cell(nrow,ncol,distance + 1);
	                    q.push(node);
	                    ans[nrow][ncol] = distance + 1;
	                }
	        }
	    }
	    
	    return ans;
	}
};