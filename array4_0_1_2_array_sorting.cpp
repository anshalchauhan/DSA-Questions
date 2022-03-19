// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int numzero = 0;
        int numone = 0;
        int numtwo = 0;
        int i=0;
        
        for(int i=0;i<n;i++)
            {
                if(a[i] == 0)
                    numzero++;
                else if(a[i] == 1)
                    numone++;
                else
                    numtwo++;
            }
        
        while(numzero--)
            a[i++] = 0;
        
        while(numone--)
            a[i++] = 1;
            
        while(numtwo--)
            a[i++] = 2;
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends