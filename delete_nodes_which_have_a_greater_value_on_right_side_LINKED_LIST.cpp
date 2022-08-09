class Solution
{
    public:
    
    void insertwhenlesser(Node *&ans,Node *&anshead,int val)
    {
        Node *n = new Node(val);
        if(ans == NULL) 
        {
            anshead = n;
            ans = n;
            ans->next = NULL;
            return;
        }
        ans->next = n;
        ans = n;
        ans->next = NULL;
    }
    
    void insertwhengreater(Node *&ans,Node *&anshead,int val)
    {
        Node *n = new Node(val);
        Node *head = anshead;
        
        while(head != NULL)
        {
            if(head->data >= n->data) head = head->next;
            else 
            {
                if(head == anshead) 
                {
                    anshead = n;
                    ans = n;
                    anshead->next = NULL;
                    ans->next = NULL;
                }
                else
                {
                    head->next = NULL;
                    head->data = n->data;
                    ans = head;
                }
                break;
            }
        }
    }
    
    
    Node *compute(Node *head)
    {
        Node *curr = head, *ans = NULL, *anshead = NULL;
        
        while(curr != NULL)
        {
            if(ans == NULL || curr->data <= ans->data) insertwhenlesser(ans,anshead,curr->data);
            else insertwhengreater(ans,anshead,curr->data);
            
            curr = curr->next;
        }
        
        return anshead;
    }
    
};