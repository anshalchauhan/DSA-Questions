class Solution{
  public:
    
    bool isKPartitionPossible(int a[], int n, int k)
    {
        int sum = 0;
         for(int i=0;i<n;i++)
             sum += a[i];
         
        sort(a,a+n);
        int l = 0;
        if(sum%k != 0) return false;
        
        allsubsequence(a,n,sum/k,0,l);
        
        if(l >= k) return true;
        else return false;
    }
    
    void allsubsequence(int a[],int n,int sum,int i,int &l)
    {
        if(sum == 0){
            l++;
            return;
        }
        
        if(i == n || sum < 0) return;
    
        for(int j=i;j<n;j++)
 	 	{       
 	 		if(j!=i && a[j] == a[j-1]) continue;
        	allsubsequence(a,n,sum-a[j],j+1,l);
 	 	} 	
	} 
};