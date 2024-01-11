class Solution{
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        Node* node = new Node(0);
        int start = 0;
        solve(node,str,start,str.size());
        return node;
    }
    
    // function to create tree recursively
    void solve(Node* node,string &str,int& start,int end)
    {
        
        if(start < end && isdigit(str[start]))
        {
            int sum = 0;
            while(start < end && isdigit(str[start]))
            {
                sum = sum*10 + str[start] - '0';
                start++;
            }
            
            node->data = sum;
        }
        
        if(start < end && str[start] == '(')
        {
            node->left = new Node(0);
            start++;
            solve(node->left,str,start,end);
            
            if(!node->left->data) node->left = NULL;
        }
        
        if(start < end && str[start] == '(')
        {
            node->right = new Node(0);
            start++;
            solve(node->right,str,start,end);
            
            if(!node->right->data) node->right = NULL;
        }
        
        if(start >= end || str[start] == ')') {start++; return;}
    }
};