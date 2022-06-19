bool isCircular(Node *head)
{
    Node *current = head;
    while(current != NULL)
    {
        if(current->next == head) return true;
        current = current->next;
    }
    return false;
}