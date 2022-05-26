class Solution{
    public:
    int minSubset(vector<int> &arr,int n){
        long long int sum = 0,ans = 0,indsum = 0;
        
        for(int i=0;i<n;i++)
            sum += arr[i];
            
        sort(arr.rbegin(),arr.rend());
            
        for(int i=0;i<n;i++)
        {
            sum -= arr[i];
            indsum += arr[i];
            ans++;
            if(indsum > sum)    break;
            
        }
    return ans;
    }
};
