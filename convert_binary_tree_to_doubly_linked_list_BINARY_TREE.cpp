class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        Node *head = NULL, *node = NULL;
        inorder(root,head,node);
        return head;
    }
    
    void inorder(Node* root,Node* &head,Node* &node)
    {
        if(!root) return;
        inorder(root->left,head,node);
        insert_node(root->data,head,node);
        inorder(root->right,head,node);
    }
    
    void insert_node(int value,Node* &head,Node* &node)
    {
        if(!head)
        {
            head = new Node();
            head->data = value;
            node = head;
        }
        else
        {
            Node* node1 = new Node();
            node1->data = value;
            node->right = node1;
            node1->left = node;
            node = node1;
        }
    }
};