class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 && nums[0]) return nums[0];
        vector<int> hash(n,-1);
        int first = notadjacent(n-1,0,nums,hash);
        int second = notadjacent(n,1,nums,hash);
        return max(first,second);
    }
    
    int notadjacent(int n,int i,vector<int>& nums,vector<int> hash)
    {
        if(i >= n) return 0;
        
        if(hash[i] != -1) return hash[i];
        
        int left = nums[i] + notadjacent(n,i+2,nums,hash);
        int right = notadjacent(n,i+1,nums,hash);
        
        return hash[i] = max(left,right); 
    }
};