class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        unordered_map<int,stack<int>> umap;
        
        for(int i=0;i<2*e;i += 2)   umap[A[i]].push(A[i+1]);
        
        for(int i=0;i<2*e;i += 2)
        {
            if(!umap[B[i]].empty() && umap[B[i]].top() == B[i+1]) umap[B[i]].pop();
            else return 0;
        }
        
        return 1;
    }
};