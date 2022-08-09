class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *first = head, *second = head, *prev = NULL;
        bool flag = false;
        
        while(second->next != NULL && second->next->next != NULL)
        {
            prev = first;
            first = first->next;
            second = second->next->next;
            if(first == second) 
            {   flag = true;
                break; }
        }
        
        if(first == head && flag)   prev->next = NULL;
            
        else if(first != head && flag)
        {
            first = head;
            
            while(first != NULL)
            {
                if(first->next == second->next)
                    {
                        second->next = NULL;
                        break;
                    }
                first = first->next;
                second = second->next;
            }
        }
        
        else    return;
    }
};