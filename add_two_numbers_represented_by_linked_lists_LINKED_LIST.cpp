class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    
    void insertathead(struct Node* &head, int val) 
    {
        struct Node* n = new struct Node(val);
        n->next = head;
        head = n;
    }
    
    struct Node* reverse(struct Node* head)
    {
        struct Node *curr = head, *prev = NULL, *next = NULL; 
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        struct Node* ans = NULL;
        
        first = reverse(first);
        second = reverse(second);
        
        int num1=0;
        
        while(first != NULL || second != NULL)
        {
            if(first != NULL) 
            {
                num1 += first->data;
                first = first->next;
            }
                
            if(second != NULL)
            {
                num1 += second->data;
                second = second->next;
            }
            
            if(num1/10 == 0) 
            {
                insertathead(ans,num1);
                num1 = 0;
            }
            
            else 
            {
                insertathead(ans,num1%10);
                num1 = num1/10;
            }
        }
        
        if(num1 != 0) insertathead(ans,num1);
        return ans;
    }
};