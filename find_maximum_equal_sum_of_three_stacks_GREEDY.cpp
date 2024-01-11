class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        int sum1 = 0, sum2 = 0, sum3 = 0;
        
        for(int i=0;i<n1;i++)
            sum1 += s1[i];
            
        for(int i=0;i<n2;i++)
            sum2 += s2[i];
            
        for(int i=0;i<n3;i++)
            sum3 += s3[i];
        
        int i = 0, j = 0, k = 0;
        int max_of_three;
        
        for(;i < n1 && j < n2 && k < n3;)
        {
            if(sum1 == sum2 && sum2 == sum3) return sum1;
            
            max_of_three = max(sum1,max(sum2,sum3));
            
            if(sum1 == max_of_three)
            {
                sum1 -= s1[i];
                i++;
            }
            
            if(sum2 == max_of_three)
            {
                sum2 -= s2[j];
                j++;
            }
            
            if(sum3 == max_of_three)
            {
                sum3 -= s3[k];
                k++;
            }
        }
        
        return 0;
    }
};