int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> hash(n, vector<int> (4,-1));
    hash[0][0] = max(points[0][1],points[0][2]);
    hash[0][1] = max(points[0][0],points[0][2]);
    hash[0][2] = max(points[0][0],points[0][1]);
    hash[0][3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    
    for(int i=1;i<n;i++)
        for(int last=0;last<4;last++)
        {
            hash[i][last] = 0;
                for(int j=0;j<3;j++)
            		if(j != last)
                    {	int point = points[i][j] + hash[i-1][j];
               			hash[i][last] = max(hash[i][last],point);
                    }
        }
return hash[n-1][3];
}