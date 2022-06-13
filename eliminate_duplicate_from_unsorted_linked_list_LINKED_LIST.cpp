class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head) 
    {
        map<int,int> map1;
        Node *current = head, *prev = NULL, *next = NULL;
        
        while(current != NULL)
        {
            next = current->next;
            map1[current->data]++;
            
            if(map1[current->data] > 1) prev->next = next;
            else    prev = current;
                    
            current = next;
        }
        return head;
    }
};