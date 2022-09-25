class Solution
{
public:
    int countPairs(Node* root1, Node* root2, int x)
    {
        int count = 0;
        map<int,int> map1;
        queue<Node*> q;
        q.push(root1);
        
        while(!q.empty())
        {
            Node* node1 = q.front();
            q.pop();
            map1[node1->data]++;
            if(node1->left) q.push(node1->left);
            if(node1->right) q.push(node1->right);
        }
        
        q.push(root2);
        
        while(!q.empty())
        {
            Node* node2 = q.front();
            q.pop();
            if(map1[x - node2->data]) count++;
            if(node2->left) q.push(node2->left);
            if(node2->right) q.push(node2->right);
        }
        
        return count;
    }
};