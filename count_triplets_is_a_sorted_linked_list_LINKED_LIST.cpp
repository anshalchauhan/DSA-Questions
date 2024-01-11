//User function Template for C++

// Function to copy the linked list
Node* copy(Node* head)
{
    Node* current = head, *ans = new Node(-1);
    Node* temp = ans;
    
    while(current)
    {
        Node* newNode = new Node(current->data);
        temp->next = newNode;
        temp = newNode;
        current = current->next;
    }
    
    return ans->next;
}

// Function to reverse linked list
Node* reverse(Node* head)
{
    Node* current = head, *prev = NULL, *next = NULL;
    
    while(current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

int countTriplets(struct Node* head, int x) 
{ 
    // code here.
    int ans = 0;
    Node *node = head, *current = head, *revcurrent = NULL;
    
    // creating a copy of given linked list
    revcurrent = copy(head);
    
    // reversing the copied linked list
    revcurrent = reverse(revcurrent);
    
    while(node->next->next)
    {
        int sum = node->data;
        Node* cindex = node, *rindex = revcurrent;
        
        while(cindex->data < rindex->data)
        {
            if(rindex->data == sum || sum + cindex->data + rindex->data > x)
                rindex = rindex->next;
                
            else if(cindex->data == sum || sum + cindex->data + rindex->data < x)
                cindex = cindex->next;
        
            else
            {
                ans++;
                cindex = cindex->next;
                rindex = rindex->next;
            }
        }
        
        node = node->next;
    }
    
    return ans;
}