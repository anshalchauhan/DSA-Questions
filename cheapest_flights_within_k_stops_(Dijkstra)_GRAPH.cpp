class Node {
  public:
    int stops;
    int price;
    int city;
    Node(int stops,int price,int city)
    {
        this->stops = stops;
        this->price = price;
        this->city = city;
    }
};


class Solution {
  public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        vector<pair<int,int>> adj[n];
        vector<int> cost(n,INT_MAX);
        queue<Node*> pq;
        Node* node = new Node(0,0,src);
        pq.push(node);
        cost[src] = 0; 
        
        //creating the adjacency list
        for(auto a:flights)
            adj[a[0]].push_back({a[1],a[2]});
        
        while(!pq.empty())
        {
            node = pq.front();
            int prev_stops = node->stops;
            int prev_price = node->price;
            int prev_city = node->city;
            pq.pop();
            
            if(prev_stops > k) break;
            
            for(auto a:adj[prev_city])
            {
                int city = a.first;
                int price = a.second;
                
                if(cost[city] > price + prev_price && prev_stops <= k)
                {
                    cost[city] = price + prev_price;
                    node = new Node(prev_stops + 1,cost[city],city);
                    pq.push(node);
                }
            }
        }
        
        if(cost[dst] == INT_MAX) return -1;
        return cost[dst];
    }
};