class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        int count = 0;
        node *current = head, *prev = NULL, *next = NULL;
        
        while(current != NULL && count < k)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        
        if(current != NULL) head->next = reverse(current, k);
        
        return prev;
    }
};