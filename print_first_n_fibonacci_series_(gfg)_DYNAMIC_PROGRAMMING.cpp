class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> printFibb(int n) 
    {
        vector<long long> store(n,-1);
        store[0] = 1;
        store[1] = 1;
        solve(n,store);
        return store;
    }
    
    long long solve(int n,vector<long long>& store)
    {
        if(store[n-1] != -1)    return store[n-1];
        return store[n-1] = solve(n-1,store) + solve(n-2,store);
    }
};