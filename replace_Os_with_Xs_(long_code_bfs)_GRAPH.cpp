class Node
{
public:
    int row;
    int col;
    bool edge;
    Node(int row,int col,bool edge)
    {
        this->row = row;
        this->col = col;
        this->edge = edge;
    }
};

class Solution{
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>> ans(n,vector<char>(m));
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 'O' && !visited[i][j])
                {
                    ans[i][j] = 'O';
                    visited[i][j] = 1;
                    bool edge = true;
                    if(!(i >= 1 && i < n-1 && j >= 1 && j < m-1)) edge = false;
                    bfs(n,m,i,j,edge,mat,visited,ans);
                }
                
                else if(mat[i][j] == 'X')
                    ans[i][j] = 'X';
            }
        
        return ans;
    }
    
    void bfs(int n,int m,int i,int j,bool edge,vector<vector<char>>& mat,
    vector<vector<int>>& visited,vector<vector<char>>& ans)
    {
        bool finaledge = edge;
        queue<Node*> q;
        queue<pair<int,int>> store;
        Node* node = new Node(i,j,edge);
        q.push(node);
        store.push({i,j});
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
        while(!q.empty())
        {
            node = q.front();
            q.pop();
            int row = node->row;
            int col = node->col;
            bool nedge = node->edge;
            finaledge = finaledge && nedge;
            
            for(int k=0;k<4;k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && !visited[nrow][ncol] && mat[nrow][ncol] == 'O')
                {
                    if(!(nrow >= 1 && nrow < n-1 && ncol >= 1 && ncol < m-1))
                        nedge = false;
                    
                    ans[nrow][ncol] = 'O';
                    visited[nrow][ncol] = 1;
                    node = new Node(nrow,ncol,nedge);
                    q.push(node);
                    store.push({nrow,ncol});
                }
            }
        }
        
        if(finaledge)
        {
            while(!store.empty())
            {
                int row = store.front().first;
                int col = store.front().second;
                store.pop();
                ans[row][col] = 'X';
            }
        }
    }
};