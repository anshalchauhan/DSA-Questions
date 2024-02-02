class Solution{
  public:
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> nodes;
        inorder(root,nodes);
        int index = nodes.size()-1;
        createHeap(root,nodes,index);
    }
    
    void inorder(Node* root,vector<int>& nodes)
    {
        if(!root) return;
        inorder(root->left,nodes);
        nodes.push_back(root->data);
        inorder(root->right,nodes);
    }
    
    void createHeap(Node* root,vector<int>& nodes,int& index)
    {
        if(!root) return;
        if(index < 0) return;
        
        root->data = nodes[index];
        index--;
        createHeap(root->right,nodes,index);
        createHeap(root->left,nodes,index);
        
    }
};