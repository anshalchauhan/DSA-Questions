class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> hash(N,vector<int>(W+1,-1));
        return findmax(N-1,W,val,wt,hash);
    }
    
    int findmax(int n,int w,int val[],int wt[],vector<vector<int>>& hash)
    {
        if(w == 0) return 0;
        if(n == 0) return w/wt[0]*val[0];
        if(hash[n][w] != -1) return hash[n][w];
        int take = -1e9;
        if(wt[n] <= w) take = val[n] + findmax(n,w-wt[n],val,wt,hash);
        int nottake = findmax(n-1,w,val,wt,hash);
        return hash[n][w] = max(take,nottake);
    }
};
