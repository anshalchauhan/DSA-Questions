class Solution
{
    public:
    Node *copyList(Node *head)
    {
        unordered_map<Node*,Node*> umap;
        
        Node* newhead = new Node(-1);
        Node* temp = newhead;
        Node* curr = head;
        
        while(curr)
        {
            Node* p = new Node(curr->data);
            temp->next = p;
            temp = p;
            
            umap[curr] = temp;
            
            curr = curr->next;
        }
        
        newhead = newhead->next;
        curr = head;
        Node* newcurr = newhead;
        
        while(curr)
        {
            if(curr->arb)
                newcurr->arb = umap[curr->arb];
            
            curr = curr->next;
            newcurr = newcurr->next;
        }
        
        return newhead;
    }

};