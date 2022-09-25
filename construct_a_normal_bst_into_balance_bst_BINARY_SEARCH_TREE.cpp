void inorder(Node* root,vector<int>& nodes)
{
    if(!root) return;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}


Node* create_node(int i,int j,vector<int>& nodes)
{
    if(i > j) return NULL;
    int m = (i+j)/2;
    Node* ans = new Node(nodes[m]);
    
    ans->left = create_node(i,m-1,nodes);
    ans->right = create_node(m+1,j,nodes);
    return ans;
}

Node* buildBalancedTree(Node* root)
{
    vector<int> nodes;
    inorder(root,nodes);
    int i = 0, j = nodes.size()-1;
    Node* ans = create_node(i,j,nodes);
    return ans;
}