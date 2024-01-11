class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        Node* curr = head;
        
        while(curr && --k)
            curr = curr->next;
        
        if(curr->next)
        {
            Node* newhead = curr->next;
            curr->next = NULL;
            
            Node* newcurr = newhead;
            
            while(newcurr->next)
                newcurr = newcurr->next;
            
            newcurr->next = head;
            head = newhead;
        }
        
        return head;
    }
};