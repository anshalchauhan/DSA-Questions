class Solution{
  public:
    //Function to check whether the list is palindrome.
    Node *reverse(Node *head)
    {
        Node *curr = head, *next = NULL, *prev = NULL;
        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(Node *head)
    {
        Node *rhead = NULL, *pointer = NULL, *curr = head;
        
        while(curr != NULL)
        {
            Node *n = new Node(curr->data);
            if(rhead == NULL) 
            {
                rhead = n;
                pointer = n;
                continue;
            }
            
            pointer->next = n;
            pointer = n;
            curr = curr->next;
        }
        
        rhead = reverse(rhead);
        curr = head;
    
        while(curr != NULL)
        {
            if(curr->data != rhead->data) return false;
            curr = curr->next;
            rhead = rhead->next;
        }
        
        return true;
    }
};