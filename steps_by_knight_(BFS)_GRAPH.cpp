class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int ans = INT_MAX;
	    vector<vector<int>> visited(N+1,vector<int>(N+1,0));
	    queue<pair<pair<int,int>,int>> q;
	    q.push({{KnightPos[0],KnightPos[1]},0});
	    visited[KnightPos[0]][KnightPos[1]] = 1;
	    
	    //creating 2 arrays to visit all the position a knight can reach
	    int delrow[] = {-2,-2,-1,-1,2,2,1,1};
	    int delcol[] = {-1,1,-2,2,-1,1,-2,2};
	    
	    while(!q.empty())
	    {
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        
	        if(row == TargetPos[0] && col == TargetPos[1])
	            ans = min(ans,steps);
	        
	         
	        for(int k=0;k<8;k++)
	        {
	            int nrow = row + delrow[k];
	            int ncol = col + delcol[k];
	            
	            if(nrow >= 1 && nrow <= N && ncol >= 1 && ncol <= N
	            && !visited[nrow][ncol])
	            {
	                visited[nrow][ncol] = 1;
	                q.push({{nrow,ncol},steps+1});
	            }
	        }
	    }
	    
	    if(ans == INT_MAX) ans = -1;
	    return ans;
	}
};