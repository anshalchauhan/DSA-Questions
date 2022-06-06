class Solution{
    public:
    long long int mod = (long long int)(1e9+7);
    
    long long int findMaxProduct(vector<int>&a, int n)
    {
        if(a.size() == 0) return 0;
    
        long long int poscount=0, negcount=0, zerocount = 0, prod = 1, max1 = INT_MIN, ele;
        
        for(int i=0;i<n;i++)
        {
            ele = (long long int)(a[i]);
            
            if(ele == 0)
            {
                zerocount++;
                continue;
            }
            
            if(ele > 0) poscount++;
            
            if(ele < 0) 
            {
                negcount++;
                max1 = max(max1,ele);
            }
            
            prod = (prod%mod)*(ele%mod);
        }
        
        if(prod < 0 && (negcount > 1 || poscount > 0)) prod /= max1;
        
        if(zerocount > 0 && poscount == 0 && negcount < 2) prod = 0;
        
        return prod%mod;
    }
};