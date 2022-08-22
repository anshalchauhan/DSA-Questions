void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    *head1_ref = head;
    
    Node *first = head, *second = head;   
    while(second->next != head && second->next->next != head)
    {
        first = first->next;
        second = second->next->next;
    }
    
    if(second->next != head) second = second->next;
    
    second->next = first->next;
    *head2_ref = first->next;
    first->next = *head1_ref;
}