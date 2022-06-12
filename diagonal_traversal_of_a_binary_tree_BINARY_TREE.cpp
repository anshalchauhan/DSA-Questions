vector<int> diagonal(Node *root)
{
   vector<int> ans;
   queue<Node*> que;
   que.push(root);
   
   while(!que.empty())
    {
        Node* root1 = que.front();
        que.pop();
        while(root1)
        {
            if(root1->left) que.push(root1->left);
            ans.push_back(root1->data);
            root1 = root1->right;
        }
    }
            
    return ans;
}