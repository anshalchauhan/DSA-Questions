class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        
        long long int min1 = INT_MAX;
        for(int i=0;i<=n-m;i++)
        {
            long long int temp = a[i+m-1] - a[i];
            min1 = min(min1,temp);
        }
    return min1;
    }   
};