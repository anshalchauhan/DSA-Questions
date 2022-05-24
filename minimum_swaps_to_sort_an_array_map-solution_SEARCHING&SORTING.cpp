class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    int count = 0;
	    unordered_map<int,int> mp;
	    
	    for(int i=0;i<n;i++)
	        mp[nums[i]] = i;
	    
	    sort(nums.begin(),nums.end());
	    
	    for(int i=0;i<n;i++)
	        while(mp[nums[i]] != i)
	        {
	            count++;
	            swap(nums[i],nums[mp[nums[i]]]);
	        }
	        
	    return count; 
	}
};