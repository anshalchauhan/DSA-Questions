int countTriplets(DLLNode* head, int x)
{
    int ans = 0;
    DLLNode *start = head, *currentStart = NULL, *end = head, *currentEnd = NULL;
    
    while(end->next)
        end = end->next;
    
    while(start->next->next)
    {
        int sum = start->data;
        currentStart = start->next;
        currentEnd = end;

        while(currentStart != currentEnd && currentStart->prev != currentEnd)
        {
            if((sum + currentStart->data + currentEnd->data) == x)
            {
                ans++;
                currentStart = currentStart->next;
                currentEnd = currentEnd->prev;
            }
            
            else if((sum + currentStart->data + currentEnd->data) > x)
                currentEnd = currentEnd->prev;
            else
                currentStart = currentStart->next;
        }

        start = start->next;
    }
    
    return ans;
}  