class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        vector<int> ans;
        stack<Node*> st;
        Node* node = root;
        
        while(true)
        {
            if(node)
            {
                st.push(node);
                node = node->left;
            }
            
            else
            {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                ans.push_back(node->data);
                node = node->right;
            }
        }
        
        return ans;
    }
};