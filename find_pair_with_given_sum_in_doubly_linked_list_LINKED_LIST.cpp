bool findPair(Node* head, int k)
{
    Node *curr1 = head, *curr2 = NULL;
    bool ans = false;
    
    while(curr1->next != NULL)
    {
        curr2 = curr1->next;
        while(curr2 != NULL)
        {
            if(curr2->data + curr1->data == k)    return ans = true;
            curr2 = curr2->next;
        }
        curr1 = curr1->next;
    }
    
    return ans;
}
