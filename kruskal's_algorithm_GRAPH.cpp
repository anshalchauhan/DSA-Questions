class DisjointSet {
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }
    
    int findUpar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findUpar(parent[node]);
    }
    
    void unionbySize(int u,int v)
    {
        int upar_u = findUpar(u);
        int upar_v = findUpar(v);
        
        if(upar_u == upar_v) return;
        
        if(size[upar_u] < size[upar_v])
        {
            parent[upar_u] = upar_v;
            size[upar_v] += size[upar_u];
        }
        
        else
        {
            parent[upar_v] = upar_u;
            size[upar_u] += size[upar_v];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {   
        int sum = 0;
        vector<pair<int,pair<int,int>>> edges;
        
        //creating a vector edges storing all the edges in sorted order
        for(int i=0;i<V;i++)
            for(auto it:adj[i])
            {
                int adjnode = it[0];
                int weight = it[1];
                int node = i;
                
                edges.push_back({weight,{node,adjnode}});
            }
        
        //Sorting the edges vector
        sort(edges.begin(),edges.end());
        
        //declaring the object for disjointset class
        DisjointSet ds(V);
        
        for(auto it:edges)
        {
            int u = it.second.first;
            int v = it.second.second;
            int wt = it.first;
            
            if(ds.findUpar(u) != ds.findUpar(v))
            {
                sum += wt;
                ds.unionbySize(u,v);
            }
        }
        
        return sum;
    }
};