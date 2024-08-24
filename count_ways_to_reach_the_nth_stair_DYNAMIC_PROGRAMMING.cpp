class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int mod = pow(10,9) + 7;
    int countWays(int n)
    {
        vector<int> store(n+1,-1);
        solve(n,store);
        return store[n];
    }
    
    int solve(int n,vector<int>& store)
    {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(store[n] != -1) return store[n];
        
        return store[n] = (solve(n-1,store)%mod 
        + solve(n-2,store)%mod)%mod;
    }
};
