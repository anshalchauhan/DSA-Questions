#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B) {
        
        vector<vector<int>> ans;
        vector<int> b1;
        int i=0,sum=0;
        
        sort(A.begin(),A.end());
        
        A.erase(unique(A.begin(),A.end()), A.end());
        
        int n = A.size();
        
        combsum(A,ans,b1,n,i,B,sum);
        return ans;
    }
    
    void combsum(vector<int>& A,vector<vector<int>>& ans,vector<int>& b1,int n,int i,int B,int sum)
    {
	    if(i == n || sum > B) return;

	    if(sum == B )
		    {
			    ans.push_back(b1);
			    return;
		    }

	
	    b1.push_back(A[i]);
        sum += A[i];
        combsum(A,ans,b1,n,i,B,sum);

	    b1.pop_back();
	    sum -= A[i];
	    combsum(A,ans,b1,n,i+1,B,sum);
    }

};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}