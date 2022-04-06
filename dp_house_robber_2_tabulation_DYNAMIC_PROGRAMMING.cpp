class Solution {
public:
    int rob(vector<int>& nums) {
    int n = nums.size(); 

    if(n == 1) return nums[0];
        
    int prev2,prev1,curr;
    prev1 = nums[0];
    
    for(int i=1;i<n-1;i++)
    {
    	int left = prev1;
        int right = nums[i];
        if(i>1)
        	right += prev2;
      
        curr = max(left,right);
        prev2 = prev1;
        prev1 = curr;
    }
    
    int first = prev1;
   	prev1 = nums[1];
    
     for(int i=2;i<n;i++)
    {
    	int left = prev1;
        int right = nums[i];
        if(i>2)
        	right += prev2;
      
        curr = max(left,right);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return max(first,prev1);
    }
};