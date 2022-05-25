class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<ll,ll> m1;
        ll sum = 0,count = 0;
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum == 0)
                count++;
            if(m1[sum - 0])
                count += m1[sum - 0];
            
            m1[sum]++;
        }
    return count;
    }
};