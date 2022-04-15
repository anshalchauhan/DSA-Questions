class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> hash(n,vector<int> (W+1,-1));
       return findmax(W,n-1,wt,val,hash);
    }
    
    int findmax(int W,int n,int wt[],int val[],vector<vector<int>>& hash)
    {
        if(n == 0 && wt[0] <= W) return val[n];
        if(n == 0) return 0;
        if(hash[n][W] != -1) return hash[n][W];
        
        int take = 0;
        if(wt[n] <= W) take = val[n] + findmax(W-wt[n],n-1,wt,val,hash);
        int nottake = findmax(W,n-1,wt,val,hash);
        return hash[n][W] = max(take,nottake);
    }
};