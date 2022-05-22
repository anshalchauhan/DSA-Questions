/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    static bool compare(vector<int> &a,vector<int> &b) {      
        if(a[2] == b[2])
            return a[1]<b[1];
            
        return a[2]<b[2];
    }
            
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        vector<vector<int>> store;
        inorder(root,store,0,0);
        sort(store.begin(),store.end(),compare);
        
        ans.push_back(store[0][0]);
        
        for(int i=1;i<store.size();i++)
                if(store[i][2] != store[i-1][2])
                    ans.push_back(store[i][0]);
    
        return ans;    
    }
    
    void inorder(Node* root,vector<vector<int>>& store,int x,int y)
    {
        if(root == nullptr) return;
        inorder(root->left,store,x+1,y-1);
        store.push_back({root->data,x,y});
        inorder(root->right,store,x+1,y+1);
    }
};