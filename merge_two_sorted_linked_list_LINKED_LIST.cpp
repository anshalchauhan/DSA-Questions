Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node* temp = NULL, *head = NULL;
    
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            if(!head) head = head1;
            if(temp) temp->next = head1;
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            if(!head) head = head2;
            if(temp) temp->next = head2;
            temp = head2;
            head2 = head2->next;
        }
    }
    
    while(head1)
    {
    	if(!head) head = head1;
        if(temp) temp->next = head1;
       	temp = head1;
        head1 = head1->next;
    }
    
    while(head2)
    {
       	if(!head) head = head2;
        if(temp) temp->next = head2;
      	temp = head2;
        head2 = head2->next;
    }
    
    return head;
}  