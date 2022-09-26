struct Node{
    int data;
    Node* left;
    Node* right;
    
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};


class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n,0);
        if(n == 0) return ans;
        Node *root = NULL;
        
        for(int i=n-1;i>=0;i--)
        {
            root = create_tree(root,arr[i]);
            ans[i] = inorder_successor(root,arr[i]);
        }
        
        return ans;
    }
    
    Node* create_tree(Node* root,int key)
    {
        if(!root)
            return new Node(key);
        
        if(root->data > key) root->left = create_tree(root->left,key);
        else if(root->data < key) root->right = create_tree(root->right,key);
        
        return root;
    }
    
    int inorder_successor(Node* root,int key)
    {
        Node *suc = NULL;
        
        while(root)
        {
            if(root->data > key)
            {
                suc = root;
                root = root->left;
            }
            else    root = root->right;
        }
        
        if(suc) return suc->data;
        else return -1;
    }
};