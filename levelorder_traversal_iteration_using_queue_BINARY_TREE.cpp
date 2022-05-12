class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
      vector<int> ans;
      queue<Node*> q;
      q.push(node);
      while(!q.empty())
      {
          Node* node1 = q.front();
          q.pop();
          ans.push_back(node1->data);
          if(node1->left != NULL) q.push(node1->left);
          if(node1->right != NULL) q.push(node1->right);
      }
      return ans;
    }
};