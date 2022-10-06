class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        bfs(m,n,sr,sc,image[sr][sc],color,visited,image);
        return image;
    }
    
    void bfs(int m,int n,int sr,int sc,int orgcolor,int color,vector<vector<int>>& visited,vector<vector<int>>& image)
    {
        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        image[sr][sc] = color;
        int rowarray[] = {-1,0,1,0};
        int colarray[] = {0,-1,0,1};
        
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int delrow = row + rowarray[i];
                int delcol = col + colarray[i];
                
                if(delrow >= 0 && delrow < m && delcol >= 0 && delcol < n 
                   && !visited[delrow][delcol] && image[delrow][delcol] == orgcolor)
                {
                    q.push({delrow,delcol});
                    visited[delrow][delcol] = 1;
                    image[delrow][delcol] = color;
                }
            }
        }
    }
};