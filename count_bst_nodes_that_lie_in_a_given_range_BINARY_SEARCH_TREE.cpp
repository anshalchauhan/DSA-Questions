class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
        if(!root) return 0;
        int count = 0;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            Node* node = q.front();
            q.pop();
            if(node->data >= l && node->data <= h) count++;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        
        return count;
    }
};