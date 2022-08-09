class Solution{
public:
    
    void insertatend(Node *&ans, Node* &anshead, int val)
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
    
    Node* divide(int N, Node *head){
        Node *ans = NULL, *anshead = NULL, *curr = head;
        
        while(curr != NULL)
        {
            if(curr->data%2 == 0) insertatend(ans,anshead,curr->data);
            curr = curr->next;
        }
        
        curr = head;
        
        while(curr != NULL)
        {
            if(curr->data%2 != 0) insertatend(ans,anshead,curr->data);
            curr = curr->next;
        }
        
        return anshead;
    }
};