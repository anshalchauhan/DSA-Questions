class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<vector<vector<int>>> hash(n,vector<vector<int>> (2,vector<int>(3,-1)));
        return findmax(n,0,1,2,p,hash);
    }
    
    int findmax(int n,int i,int buy,int cap,vector<int>& p,vector<vector<vector<int>>>& hash)
    {
        if(i == n || cap == 0) return 0;
        if(hash[i][buy][cap] != -1) return hash[i][buy][cap];
        int profit = 0;
        if(buy) profit = max(-p[i] + findmax(n,i+1,0,cap,p,hash), findmax(n,i+1,1,cap,p,hash));
        else profit = max(p[i] + findmax(n,i+1,1,cap-1,p,hash), findmax(n,i+1,0,cap,p,hash));
        return hash[i][buy][cap] = profit;
    }
};