class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        Node *ans = NULL;
        for(int i=0;i<k;i++)
            ans = merge(ans,arr[i]);
        return ans;
    }
    
    Node *merge(Node *list1,Node *list2)
    {
        if(!list1) return list2;
        if(!list2) return list1;
        
        Node *ans = new Node(-1);
        Node *temp = ans;
        
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->data < list2->data)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }
        
        while(list1 != NULL)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        
        while(list2 != NULL)
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
        
        ans = ans->next;
        return ans;
    }
};