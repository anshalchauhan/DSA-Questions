int count(int n, vector<vector<int>>& points,int last,vector<vector<int>>& hash)
{   
    if(hash[n][last] != -1) return hash[n][last];
        
	if(n == 0)
    {
        int max1 = 0;
        for(int i=0;i<3;i++)
            if(i != last)
                max1 = max(max1,points[n][i]);
     	return hash[n][last] = max1;
    }
    
    int max1 = 0;
   	for(int i=0;i<3;i++)
    	if(i != last)
        {	int point = points[n][i] + count(n-1,points,i,hash);
        	max1 = max(max1,point);
    	}
	return hash[n][last] = max1;
}