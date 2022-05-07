class Solution {
public:
    int maxProfit(int k, vector<int>& p) {
        int n = p.size();
        vector<vector<int>> hash(n,vector<int>(k*2,-1));
	    return findmax(p,n,k*2,0,0,hash);
    }
    
    int findmax(vector<int>& p,int n,int k,int i,int j,vector<vector<int>>& hash)
    {
        if(i == n || j == k) return 0;
        if(hash[i][j] != -1) return hash[i][j];
        int profit = 0;
        if(j%2 == 0) profit = max(-p[i] + findmax(p,n,k,i+1,j+1,hash),      findmax(p,n,k,i+1,j,hash)); 
        else profit = max(p[i] + findmax(p,n,k,i+1,j+1,hash), findmax(p,n,k,i+1,j,hash));
        return hash[i][j] = profit;
    }

};