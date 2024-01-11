class Solution{
  public:
    int minSwaps(vector<int>&A, int n){
        int ans = 0;
        unordered_map<int,int> umap;
        vector<int> in;
        
        // Storing inorder traversal of a tree
        inorder(A,in,0,n-1);
        
        // Storing value index pairs in unordered map
        for(int i=0;i<n;i++)
            umap[in[i]] = i;
        
        // Sorting the inorder traversal as we know inorder traversal of bst is always sorted
        sort(in.begin(),in.end());
        
        // counting the number of swaps
        for(int i=0;i<n;i++)
            while(umap[in[i]] != i)
            {
                ans++;
                swap(in[i], in[umap[in[i]]]);
            }
        
        return ans;
    }
    
    void inorder(vector<int>& A, vector<int>& in, int str,int end)
    {
        if(str > end) return;
        inorder(A,in,2*str + 1,end);
        in.push_back(A[str]);
        inorder(A,in,2*str + 2,end);
    }
};