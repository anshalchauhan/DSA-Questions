class Solution{
    public:
    long long int mod = (int)(pow(10,9)+7);
    int Maximize(int a[],int n)
    {
        sort(a,a+n);
        long long int ans = 0;
        
        for(long long int i=0;i<n;i++)
            ans += (long)(a[i]*i);
        
        return ans%mod;
    }
};