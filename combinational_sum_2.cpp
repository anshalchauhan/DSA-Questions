class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> b;
        
        sort(candidates.begin(),candidates.end());
        
        combsum2(candidates,ans,b,0,candidates.size(),target);
        
        return ans;
    }
    
    void combsum2(vector<int> candidates,vector<vector<int>>& ans,vector<int> b,int ind,int n,int target)
    {
        
        if(target == 0) {ans.push_back(b); return; }
        
        for(int i=ind; i<n; i++)
        {
            if(i > ind && candidates[i] == candidates[i-1]) continue;
            
            if(candidates[i] > target) break;
            
            b.push_back(candidates[i]);
            combsum2(candidates,ans,b,i+1,n,target-candidates[i]);
            b.pop_back();
        }
    }
    
};