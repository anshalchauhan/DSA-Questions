string solve(Node* root,map<string,int>& map1,vector<Node*>& ans)
{
    if(!root) return "$";
    string s = "";
    
    s += to_string(root->data);
    s += "*" + solve(root->left,map1,ans);
    s += "*" + solve(root->right,map1,ans);
    
    map1[s]++;
    if(map1[s] == 2)    ans.push_back(root);
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    vector<Node*> ans;
    map<string,int> map1;
    solve(root,map1,ans);
    return ans;
}