class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        vector<int> ele;
        inorder(root,ele);
	if(K > ele.size()) return -1;
        reverse(ele.begin(),ele.end());
        return ele[K-1];
    }
    
    void inorder(Node* root, vector<int>& ele)
    {
        if(root == NULL) return;
        inorder(root->left,ele);
        ele.push_back(root->data);
        inorder(root->right,ele);
    }
    
};