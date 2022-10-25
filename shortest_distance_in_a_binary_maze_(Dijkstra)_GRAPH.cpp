class Node  {
  public:
    int row;
    int col;
    int distance;
    Node(int row,int col,int distance)
    {
        this->row = row;
        this->col = col;
        this->distance = distance;
    }
};

class compare
{
  public:
    bool operator() (Node* a, Node* b) {
        return a->distance > b->distance;
    }  
};

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int,int> source, pair<int, int> destination) {
        int ans = INT_MAX;
        int n = grid.size();
        int m = grid[0].size();
        int si = source.first, sj = source.second, di = destination.first, dj = destination.second;
        
        bfs(n,m,si,sj,di,dj,grid,ans);
        
        if(ans == INT_MAX) return -1;
        return ans;
    }
    
    void bfs(int n,int m,int si,int sj,int di,int dj,
    vector<vector<int>>& grid,int &ans)
    {
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        priority_queue<Node*, vector<Node*>, compare> pq;
        Node* node = new Node(si,sj,0);
        pq.push(node);
        dist[si][sj] = 0;
     
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        while(!pq.empty())
        {
            node = pq.top();
            pq.pop();
            
            int row = node->row;
            int col = node->col;
            int distance = node->distance;
            
            if(row == di && col == dj)
                ans = min(ans,distance);
            
            for(int k=0;k<4;k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                && grid[nrow][ncol])
                {
                    if(dist[nrow][ncol] > distance + 1)
                    {
                        dist[nrow][ncol] = distance + 1;
                        node = new Node(nrow,ncol,distance + 1);
                        pq.push(node);
                    }
                }
            }
        }
    }
};