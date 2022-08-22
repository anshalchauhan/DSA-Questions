/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key)
{
    Node *curr = *head, *prev = NULL;
    
    while(curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    
    prev->next = curr->next;
    delete curr;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref)
{
    Node *curr = *head_ref, *newhead = *head_ref, *head = *head_ref;
    Node *next = NULL, *prev = NULL;
    
    while(curr->next != head)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    head->next = curr;
    curr->next = prev;
    *head_ref = curr;
}