class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> ans;
        vector<int> store;
        uniquesubs(ans,nums,store,nums.size(),0);
        return ans;
    }
    
    void uniquesubs(vector<vector<int>>& ans,vector<int>& nums,vector<int> store,int n,int i)
    {
        if(i > n) return;
        
        if(i <= n) ans.push_back(store);
        
        for(int j=i;j<n;j++)
        {
            if(j != i && nums[j] == nums[j-1])
                continue;
            
            store.push_back(nums[j]);
            uniquesubs(ans,nums,store,n,j+1);
            store.pop_back();
        }
    }
};