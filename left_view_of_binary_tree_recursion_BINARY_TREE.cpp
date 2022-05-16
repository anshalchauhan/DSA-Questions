void findleft(Node* root,vector<int>& ans,int level)
{
    if(root == NULL) return;
    if(level == ans.size()) ans.push_back(root->data);
    findleft(root->left,ans,level+1);
    findleft(root->right,ans,level+1);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    findleft(root,ans,0);
    return ans;
}