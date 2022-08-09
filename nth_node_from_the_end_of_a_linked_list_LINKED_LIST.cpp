int getNthFromLast(Node *head, int n)
{
    int ans = -1, count = 0, temp = 0;
    Node *curr = head;
    
    while(curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    
    curr = head;
    
    while(curr != NULL)
    {
        temp++;
        if(count -temp + 1 == n) return curr->data;
        curr = curr->next;
    }
    
    return ans;
}