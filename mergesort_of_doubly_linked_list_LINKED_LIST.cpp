  Node* divide(Node* head)
    {
        Node* first = head, *second = head;
        
        while(second->next && second->next->next)
        {
            first = first->next;
            second = second->next->next;
        }
        
        return first;
    }
    
    Node* merge(Node* first,Node* second)
    {
        Node* head = new Node(INT_MIN);
        Node* temp = head;
        
        while(first && second)
        {
            if(first->data < second->data)
            {
                temp->next = first;
                if(temp->data == INT_MIN)   first->prev = NULL;
                else first->prev = temp;
                temp = first;
                first = first->next;
            }
            else
            {
                temp->next = second;
                if(temp->data == INT_MIN)   second->prev = NULL;
                else second->prev = temp;
                temp = second;
                second = second->next;
            }
        }
        
        while(first)
        {
            temp->next = first;
            first->prev = temp;
            temp = first;
            first = first->next;
        }
        
        while(second)
        {
            temp->next = second;
            second->prev = temp;
            temp = second;
            second = second->next;
        }
        
        return head->next;
    }
    
    struct Node *sortDoubly(struct Node *head)
    {
        //Basecase
        if(!head || !head->next) return head;
        
        // Divide in two parts
        Node* first = head;
        Node* middle = divide(head);
        Node* second = middle->next;
        middle->next = NULL;
        
        first = sortDoubly(first);
        second = sortDoubly(second);
        
        return merge(first,second);
    }