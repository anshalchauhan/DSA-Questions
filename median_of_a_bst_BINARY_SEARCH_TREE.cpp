void inorder(struct Node* root,vector<float>& nodes)
{
    if(!root) return;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}

// Function should return median of the BST
float findMedian(struct Node *root)
{
    vector<float> nodes;
    inorder(root,nodes);
    int size = nodes.size();
    if(size%2 == 0)
        return (nodes[size/2-1] + nodes[size/2])/2;
    else
        return nodes[size/2];
}