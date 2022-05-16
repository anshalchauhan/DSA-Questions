vector<int> reverseLevelOrder(Node *node)
{
    vector<int> ans;
    if(node == NULL) return ans;
    
    queue<Node*> q;
    q.push(node);
    
    while(!q.empty())
    {
        Node* node1 = q.front();
        q.pop();
        ans.push_back(node1->data);
        if(node1->right != NULL) q.push(node1->right);
        if(node1->left != NULL) q.push(node1->left);
    }
    
    reverse(ans.begin(),ans.end());
    return ans;
}