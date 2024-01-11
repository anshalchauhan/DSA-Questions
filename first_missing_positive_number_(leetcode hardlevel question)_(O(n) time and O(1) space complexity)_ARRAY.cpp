class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size(), ans;

        for(long long int i=0;i<n;)
        {
            if(nums[i] != INT_MIN && nums[i] - 1 < n && nums[i] - 1 > -1 && nums[i] - 1 != i)
            {
                if(nums[i] == nums[nums[i] - 1])
                    nums[i] *= -1;
                else
                    swap(nums[i],nums[nums[i] - 1]);
            }
            else
                i++;
        }

        for(int i=0;i<n;i++)
            if(i+1 != nums[i]) return i+1;

        return n+1; 
    }
};