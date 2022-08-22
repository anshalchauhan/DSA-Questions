Node *findmiddle(Node *head)
{
    Node *first = head, *second = head;
    while(second->next != NULL && second->next->next != NULL)
    {
        first = first->next;
        second = second->next->next;
    }
    return first;
}

Node *merge(Node *list1, Node *list2)
{
    if(list1 == NULL) return list2;
    if(list2 == NULL) return list1;
    
    Node *ans = new Node(-1);
    Node *temp = ans;
    
    while(list1 != NULL && list2 != NULL)
    {
        if(list1->data < list2->data)
        {
            temp->bottom = list1;
            temp = list1;
            list1 = list1->bottom;
        }
        
        else
        {
            temp->bottom = list2;
            temp = list2;
            list2 = list2->bottom;
        }
    }
    
    while(list1 != NULL)
    {
        temp->bottom = list1;
        temp = list1;
        list1 = list1->bottom;    
    }
    
    while(list2 != NULL)
    {
        temp->bottom = list2;
        temp = list2;
        list2 = list2->bottom;
    }

    ans = ans->bottom;
    return ans;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *head)
{
   if(head == NULL || head->next == NULL)   return head;
   
   Node *mid = findmiddle(head);
   Node *first = head;
   Node *second = mid->next;
   mid->next = NULL;
   
   //Recursion for further dividing the list
   first = flatten(first);
   second = flatten(second);
   
   //Mergin the lists
   return merge(first,second);
}