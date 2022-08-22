class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        
        //base case
        if(head == NULL || head->next == NULL)  return head;
        
        //breaking the linked list in two parts        
        Node *mid = findmiddle(head);
        Node *left = head;
        Node *right = mid->next;
        mid->next = NULL;
        
        //recursive calls
        left = mergeSort(left);
        right = mergeSort(right);
        
        
        //merging the linked list
        Node *result = merge(left,right);
        
        return result;
    }
    
    //Function to find the middle
    Node* findmiddle(Node* head) {
        Node *first = head, *second = head;
        
        while(second->next != NULL && second->next->next != NULL)
        {
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
    
    Node *merge(Node *left, Node *right)
    {
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        Node *result = new Node(-1);
        Node *temp = result;
        
        
        while(left != NULL && right != NULL)
        {
            if(left->data < right->data)
                {
                    temp->next = left;
                    temp = left;
                    left = left->next;
                }
            else
                {
                    temp->next = right;
                    temp = right;
                    right = right->next;
                }      
        }
        
        while(left != NULL)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        
        while(right != NULL)
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        result = result->next;
        return result;
    }
};