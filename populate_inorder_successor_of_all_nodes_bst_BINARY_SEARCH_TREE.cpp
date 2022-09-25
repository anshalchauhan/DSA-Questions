class Solution
{
public:

    void populateNext(Node *root)
    {
        Node* temp = NULL;
        inorder(root,temp);
        return;
    }
    
    void inorder(Node *root,Node*& temp)
    {
        if(!root) return;
        inorder(root->left,temp);
        if(!temp) temp = root;
        else
        {
            temp->next = root;
            temp = root;
        }
        inorder(root->right,temp);
    }
};