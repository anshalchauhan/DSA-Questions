void inorder(TreeNode<int>* root,vector<int>& nodes)
{
    if(!root) return;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}

void make_array(vector<int>& nodes1,vector<int>& nodes2,vector<int>& nodes)
{
    int i=0,j=0,i1=nodes1.size(),j1=nodes2.size();
    while(i < i1 && j < j1)
    {
        if(nodes1[i] < nodes2[j]) nodes.push_back(nodes1[i++]);
        else nodes.push_back(nodes2[j++]);
    }
    
    while(i < i1)    nodes.push_back(nodes1[i++]);
    while(j < j1)    nodes.push_back(nodes2[j++]);
}

TreeNode<int>* create_tree(int i,int j,vector<int>& nodes)
{
    if(i > j) return NULL;
    int m = (i+j)/2;
    TreeNode<int>* root = new TreeNode<int>(nodes[m]);
    
    root->left = create_tree(i,m-1,nodes);
    root->right = create_tree(m+1,j,nodes);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    vector<int> nodes1,nodes2,nodes;
    inorder(root1,nodes1);
    inorder(root2,nodes2);
    make_array(nodes1,nodes2,nodes);
    int i=0,j=nodes.size()-1;
    TreeNode<int>* root = create_tree(i,j,nodes);
    return root;
}