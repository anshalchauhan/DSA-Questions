Node* insert(Node* root, int key) {
    if(!root) 
    {
        Node* node = new Node(key);
        return node;
    }
    
    Node* curr = root;
    
    while(true)
    {
        if(curr->data == key) break;
        
        if(curr->data > key)
        {
            if(curr->left) curr = curr->left;
            else
            {
                Node* node = new Node(key);
                curr->left = node; 
                break;
            }
        }
        
        else
        {
            if(curr->right) curr = curr->right;
            else
            {
                Node* node = new Node(key);
                curr->right = node;
                break;
            }
        }
    }
    
    return root;
}