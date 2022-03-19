class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> map;
        int t=0;
        
        for(int i=0;i<=nums.size();i++)
        {
            map[nums[i]]++;
            if(map[nums[i]] == 2)
            {
                t = nums[i];
                break;
            }
        }
        
        return t;
    }
};