Node *myreverse(Node **head)
{
    Node *curr = *head, *prev = NULL, *next = NULL;
    
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return *head = prev;
}

long long int multiplyTwoLists (Node* l1, Node* l2)
{
    Node *curr1 = l1, *curr2 = l2;
    long long int ans = 0, mod1 = pow(10,9) + 7, count1 = -1, count2 = -1;
    
    l1 = myreverse(&l1);
    l2 = myreverse(&l2);
    
    curr1 = l1;
    curr2 = l2;
    
    while(curr1 != NULL)
    {
        count1++;
        long long int ele1 = curr1->data, product = 0;
        while(curr2 != NULL)
            {
                count2++;
                long long int ele2 = curr2->data;
                product += (ele1*ele2*(int)pow(10,count2))%mod1;
                curr2 = curr2->next;
            }
        count2 = -1;
        ans += (product*(int)pow(10,count1))%mod1;
        curr2 = l2; 
        curr1 = curr1->next;
    }
    
    return ans;
}