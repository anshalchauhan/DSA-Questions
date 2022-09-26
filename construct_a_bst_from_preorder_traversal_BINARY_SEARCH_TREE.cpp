class Solution{
public:
    //Function that constructs BST from its preorder traversal.
    Node* post_order(int pre[], int size)
    {
        int i = 0;
        Node* node = create_tree(pre,i,size-1);
        return node;
    }
    
    Node* create_tree(int pre[],int i,int j)
    {
        if(i > j) return NULL;
        
        Node* node = newNode(pre[i]);
        int k;
        
        for(k=i+1;k<=j;k++)
            if(pre[k] > pre[i]) break;
            
        node->left = create_tree(pre,i+1,k-1);
        node->right = create_tree(pre,k,j);
        
        return node;
    }
};