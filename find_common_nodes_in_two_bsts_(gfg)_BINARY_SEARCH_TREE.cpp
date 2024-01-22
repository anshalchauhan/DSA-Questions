class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    vector<int> findCommon(Node *root1, Node *root2)
    {
        Node* head1 = NULL, *head2 = NULL, *prev1 = NULL, *prev2 = NULL;
        vector<int> ans;
        
        // Flattening BSTs to Linked list
        flatten(root1,prev1,head1);
        prev1->left = NULL;
        
        flatten(root2,prev2,head2);
        prev2->left = NULL;
        
        common(head1,head2,ans);
        return ans;
    }
    
    // flattening in Inorder Traversal
    void flatten(Node* root,Node*& prev,Node*& head)
    {
        if(!root) return;
        Node* left = root->left;
        Node* right = root->right;
        
        flatten(root->left,prev,head);
        if(!prev) head = root;
        else
        {
            prev->left = NULL;
            prev->right = root;
        }
        prev = root;
        flatten(root->right,prev,head);
    }
    
    // Saving common nodes in 2 BSTs
    void common(Node* root1,Node* root2,vector<int>& ans)
    {
        while(root1 && root2)
        {
            if(root1->data < root2->data)   root1 = root1->right;
            else if(root1->data > root2->data)    root2 = root2->right;
            else 
            {
                ans.push_back(root1->data);
                root1 = root1->right;
                root2 = root2->right;
            }
        }
    }
};

