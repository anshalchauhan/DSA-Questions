class Solution
{
    public:
    
    Node* reverse(Node *head)
    {
        Node *curr = head, *prev = NULL, *next = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void insertathead(Node *&head,int val)
    {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }
    
    Node* addOne(Node *head) 
    {
        Node *start = reverse(head), *ans= NULL;
        int num = 1;
        
        while(start != NULL)
        {
            num += start->data;
            
            if(num/10 == 0) 
            {
                insertathead(ans,num);
                num = 0;
            }
            
            else
            {
                insertathead(ans,num%10);
                num /= 10;
            }
        
            start = start->next;
        }
        
        if(num != 0) insertathead(ans,num);
        
        return ans;
    }
};