node** partition(node* head)
{
    node* small = new node(-1);
    node* large = new node(-1);
    node* curr = head->next, *sp = small, *lp = large;
    int pivot = head->data;
    
    while(curr)
    {
        if(curr->data <= pivot)
        {
            sp->next = curr;
            sp = curr;
        }
        else
        {
            lp->next = curr;
            lp = curr;
        }
        curr = curr->next;
    }
    
    sp->next = NULL;
    lp->next = NULL;
    head->next = NULL;
    
    node** arr = new node*[3];
    arr[0] = small->next;
    arr[1] = head;
    arr[2] = large->next;
    
    return arr;
}

//you have to complete this function
void quickSort(struct node **headRef) {
    node* head = *headRef;
    if(!head || !head->next) return;
    
    node** arr = partition(head);
    
    if(arr[0]) quickSort(&arr[0]);
    if(arr[2]) quickSort(&arr[2]);
    
    node* small = arr[0], *smallLast = arr[0], *pivot = arr[1], *large = arr[2];
    node* curr = small;
    while(curr && curr->next)
    {
        smallLast = curr->next;
        curr = curr->next;
    }
    
    node* ans = NULL;
    if(small)
    {
        ans = small;
        if(pivot) smallLast->next = pivot;
        else smallLast->next = large;
    }
    
    if(pivot)  
    {
        if(!ans) ans = pivot;
        pivot->next = large;
    }
    
    *headRef = ans;
}