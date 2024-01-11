class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        vector<int> ans;
        int xor1 = nums[0];
        
        for(int i=1;i<nums.size();i++)
            xor1 = xor1 ^ nums[i];
        
        int x,y;
        x=y=0;
        int right_set_bit = xor1 & ~(xor1 - 1);
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]&right_set_bit) 
                x = x ^ nums[i];
            else
                y = y ^ nums[i];
        }
        
        ans.push_back(x);
        ans.push_back(y);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};