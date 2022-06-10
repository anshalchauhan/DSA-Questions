#include<bits/stdc++.h>
long long int maxProductSubset(vector<int> &a, int n)
{
     if(n == 0) return 0;
     long long int poscount=0, negcount=0, zerocount = 0, prod = 1, max1 = INT_MIN, ele, mod = 1e9+7;
        
        for(int i=0;i<n;i++)
        {
            ele = (long long int)(a[i]);
      
            if(ele == 0)
            {   zerocount++;
                continue;    }
            
            if(ele > 0) poscount++;
            
            if(ele < 0) 
            {   negcount++;
                max1 = max(max1,ele);    }
            
            prod = ((prod%mod)*(ele%mod))%mod;
        }
        
        if(prod < 0 && (negcount > 1 || poscount > 0))
        {
            prod = 1;
            bool flag = false;
            for(int i=0;i<n;i++)
            {
                ele = (long long int)(a[i]);
                if(ele == max1 && flag == false)
                {
                    flag = true;
                    continue;
                }
                
                if(ele == 0) continue;
                prod = ((prod%mod)*(ele%mod))%mod;
            }
        }
        
        if(zerocount > 0 && poscount == 0 && negcount < 2) prod = 0;
        
        return prod%mod;
}