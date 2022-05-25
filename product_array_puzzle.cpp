class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        long long int prod = 1;
        vector<long long int> ans;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i != j)  prod *= nums[j];
            }
        ans.push_back(prod);
        prod = 1;
        }
        
        return ans;
    }
};