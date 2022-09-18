class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    int dupSub(Node *root) {
        map<string,int> map1;
        solve(root,map1);
        
        for(auto it:map1)
            if(it.second >= 2) return true;
        
        return false;
    }
    
    string solve(Node* root,map<string,int> &map1)
    {
        if(!root) return "$";
        string s = "";
        if(!root->left && !root->right) return s = to_string(root->data);
        
        s += "*" + to_string(root->data); //"*" specail character added to differentiate b/w //
        s += "*" + solve(root->left,map1); // two nodes //
        s += "*" + solve(root->right,map1);
        
        map1[s]++;
        
        return s;
    }
};