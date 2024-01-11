class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
        vector<int> ans;
        stack<Node*> st;
        Node* node = root;
        st.push(node);
        
        while(!st.empty())
        {
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        
        return ans;
    }
};