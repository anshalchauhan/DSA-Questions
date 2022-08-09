void insertatend(Node *&ans, Node* &anshead,int val)
{
    Node *n = new Node(val);
    if(ans == NULL) 
    {
        anshead = n;
        ans = n;
        ans->next = NULL;
        return;
    }
    ans->next = n;
    ans = n;
    ans->next = NULL;
}

Node* findIntersection(Node* head1, Node* head2)
{
    Node *curr = head1, *ans = NULL, *anshead = NULL;
    map<int,int> count;
    
    while(curr != NULL)
    {
        count[curr->data]++;
        curr = curr->next;
    }
    
    curr = head2;
    
    while(curr != NULL)
    {
        if(count[curr->data]) 
        {
            insertatend(ans,anshead,curr->data);
            count[curr->data]--;
        }
        curr = curr->next;
    }
    
    return anshead;
}