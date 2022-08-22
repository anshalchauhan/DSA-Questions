long long multiplyTwoLists (Node* l1, Node* l2)
{
    long long a = 0, b = 0, m = pow(10,9) + 7;

    while(l1)
    {
        a = (a*10 + l1->data)%m;
        l1 = l1->next;
    }
    
    while(l2)
    {
        b = (b*10 + l2->data)%m;
        l2 = l2->next;
    }
    
    return (a*b)%m%m;
}