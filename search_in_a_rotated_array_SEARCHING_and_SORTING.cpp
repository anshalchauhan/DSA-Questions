class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return bsearch(nums,target,0,n-1);
    }
    
    int bsearch(vector<int>& nums,int target,int low,int high)
    {
        if(high >= low)
        {
            int mid = (low + high)/2;
            
            if(nums[mid] == target)
                return mid;
            
            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= target && target < nums[mid])
                    return bsearch(nums,target,low,mid-1);
                else
                    return bsearch(nums,target,mid+1,high);
            } 
            
            else
            {
                if(nums[high] >= target && target > nums[mid])
                    return bsearch(nums,target,mid+1,high);
                else
                    return bsearch(nums,target,low,mid-1);
            }
        }
        return -1;
    }
};