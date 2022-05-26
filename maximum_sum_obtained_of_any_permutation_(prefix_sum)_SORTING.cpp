class Solution {
public:
    long long int mod = (long long int)(pow(10,9)+7);
    
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> index(n+1,0);
        
        long long int sum = 0;
        
        for(int i=0;i<requests.size();i++)
        {
           index[requests[i][0]] += 1;
           index[requests[i][1] + 1] += -1;
        }
        
        for(int i=1;i<n;i++)
            index[i] += index[i-1];
        
        sort(nums.rbegin(),nums.rend());
        sort(index.rbegin(),index.rend());
        
        for(int i=0;i<n;i++)
            sum += ((nums[i])%mod)*((index[i])%mod)%mod;
        
        return sum%mod;
    }
};