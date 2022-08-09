int intersectPoint(Node* head1, Node* head2)
{
    Node *curr1 = head1, *curr2 = head2;
    int count1=0,count2=0,min1=0;
    
    while(curr1 != NULL)
    {
        count1++;
        curr1 = curr1->next;
    }
    
    while(curr2 != NULL)
    {
        count2++;
        curr2 = curr2->next;
    }
    
    min1 = min(count1,count2);
    
    curr1 = head1;
    curr2 = head2;
    
    while(count1 != min1)
    {
        count1--;
        curr1 = curr1->next;
    }
    
    while(count2 != min1)
    {
        count2--;
        curr2 = curr2->next;
    }
    
    
    while(min1--)
    {
        if(curr1 == curr2) return curr1->data;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    
    return -1;
}