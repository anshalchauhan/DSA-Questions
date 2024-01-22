void inorder(Node* root,int& count)
{
    if(!root) return;
    inorder(root->left,count);
    count++;
    inorder(root->right,count);
}

void findMedian(Node* root,int& med,Node*& prev,Node*& node1,Node*& node2)
{
    if(!root) return;
    findMedian(root->left,med,prev,node1,node2);
    med--;
    if(med == 0) 
    {
        node1 = root;
        node2 = prev;
        return;
    }
    prev = root;
    findMedian(root->right,med,prev,node1,node2);
}
// Function should return median of the BST
float findMedian(struct Node *root)
{
    if(!root) return 0;
    
    Node* prev = NULL, *node1 = NULL, *node2 = NULL;
    int count = 0, med = 0;
    inorder(root,count);
    med = count/2 + 1;
    findMedian(root,med,prev,node1,node2);
    
    if(count%2 != 0) return float(node1->data);
    return  (float(node1->data) + float(node2->data))/2;
}