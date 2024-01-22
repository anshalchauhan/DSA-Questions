struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = NULL;    
    }
};

class Solution{
    public:
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n,0);
        Node* root = NULL, *succ;
        for(int i=n-1;i>=0;i--)
        {
            succ = NULL;
            insert(root,arr[i],succ);
            ans[i] = (succ) ? succ->data : -1;
        }
        
        return ans;
    }
    
    void insert(Node*& root,int data,Node*& succ)
    {
        if(!root)   {   root = new Node(data);  return; }
        Node* curr = root;

        while(true)
        {
            if(curr->data > data)
            {
                succ = curr;
                if(curr->left) curr = curr->left;
                else    {   curr->left = new Node(data);    break;  }
            }
            else
            {
                if(curr->right) curr = curr->right;
                else    {   curr->right = new Node(data);   break;  }
            }
        }
    }
};