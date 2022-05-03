class Solution{
public:
	// Function to find maximum product subarray
	long long maxProduct(vector<int> a, int n) {
	    long long int p = 1, q = 1, max1 = a[0];
	    
	    for(int i=0;i<n;i++)
	    {
            p *= a[i];
            q *= a[i];
            max1 = max(p,max(q,max1));
            if(p == 0)
            {
                p = 1;
                q = 1;
            }
            
            if(p < 0 && q < 0)   q = 1;
	    }
	return max1;
	}
};