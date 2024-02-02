class compare {
    public:
        bool operator() (Node* a,Node* b)   {
            return a->data > b->data;            
        }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergeKLists(Node *arr[], int K)
    {
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        priority_queue<Node*,vector<Node*>,compare> pq;
        
        for(int i=0;i<K;i++)
            pq.push(arr[i]);
            
        while(!pq.empty())
        {
            Node* node = pq.top();
            pq.pop();
            temp->next = node;
            temp = node;
            
            if(node->next)  pq.push(node->next);
        }
        
        return ans->next;
    }
};