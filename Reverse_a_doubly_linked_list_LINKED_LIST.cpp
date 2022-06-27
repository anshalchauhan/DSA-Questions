Node* reverseDLL(Node* head)
{
    Node *current = head, *next = NULL, *prev = NULL;
    
    while(current != NULL)
    {
        next = current->next;
        current->prev = next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}
