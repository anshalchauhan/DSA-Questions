class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int sum = 0, lsum = 0, lnum = 0, rsum = 0, rnum = 0;
        
        for(int i=0;i<n;i++)
            sum += nums[i];
        
        for(int i=0;i<n;i++)
        {
            rsum = sum - lsum - nums[i];
            rnum = n - lnum - 1;
            ans.push_back(abs(lsum - lnum*nums[i]) + abs(rsum - rnum*nums[i]));
            lsum+=nums[i];
            lnum++;
        }
    return ans;
    }
};