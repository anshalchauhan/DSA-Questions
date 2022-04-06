int maximumNonAdjacentSum(vector<int> &nums){
	vector<int> dp(nums.size(),0);
    dp[0] = nums[0];
    
    for(int i=1;i<nums.size();i++)
    {
    	int left = dp[i-1];
        int right = nums[i];
        if(i>1)
            right += dp[i-2];
        dp[i] = max(left,right);
    }
    return dp[nums.size()-1];
}
