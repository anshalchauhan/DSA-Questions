class Node {
  public:
    int row;
    int col;
    int effort;
    Node(int row,int col,int effort)
    {
        this->row = row;
        this->col = col;
        this->effort = effort;
    }
};

class Compare {
  public:
    bool operator() (Node* a,Node* b) {
        return a->effort > b->effort;
    }
};

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<Node*, vector<Node*>, Compare> pq;
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        Node* node = new Node(0,0,0);
        pq.push(node);
        dist[0][0] = 0;
        
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,-1,0,1};
        
        while(!pq.empty())
        {
            node = pq.top();
            pq.pop();
            
            int row = node->row;
            int col = node->col;
            int effort = node->effort;
            
            if(row == n-1 && col == m-1)
                return effort;
            
            for(int k=0;k<4;k++)
            {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    int current_effort = abs(heights[row][col] - heights[nrow][ncol]);
                    current_effort  = max(effort,current_effort);
                    if(current_effort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol] = current_effort;
                        node = new Node(nrow,ncol,current_effort);
                        pq.push(node);
                    }
                }
            }
        }
        
        return 0;
    }
};