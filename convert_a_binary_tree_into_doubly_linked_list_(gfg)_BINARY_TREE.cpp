// This function should return head to the DLL
class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* prev = NULL, *head = NULL; 
        solve(root,prev,head);
        return head;
    }
    
    void solve(Node* root, Node* &prev, Node* &head)
    {
        if(!root) return;
        solve(root->left, prev, head);
        if(!prev) head = root;
        else
        {
            root->left = prev;
            prev->right = root;
        }
        prev = root;
        solve(root->right, prev, head);
    }
};