Node *removeDuplicates(Node *head)
{
    Node *current = head, *last = head, *next = NULL;
    
    while(last->next != NULL)
    {
        next = last->next;
        if(current->data == next->data) 
        {
            if(next->next == NULL)
                current->next = NULL;
            last = next;
        }
        else    
        {
            current->next = next;
            current = next;
            last = next;
        }
    }
    
    return head;
}