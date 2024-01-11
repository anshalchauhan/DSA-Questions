class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        stack<Node*> st;
        Node* node1 = node;
        
        while(node1 || !st.empty())
        {
            if(node1)
            {
                st.push(node1);
                node1 = node1->left;
            }
            
            else
            {
                Node* temp = st.top()->right;
                
                if(!temp)
                {
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                    
                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->data);
                    }
                }
                
                else node1 = temp;
            }
        }
        
        return ans;
    }
};