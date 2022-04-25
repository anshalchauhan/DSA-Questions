string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> map1,map2;
    
    for(int i=0;i<n;i++)    map1[a1[i]]++;
    for(int i=0;i<m;i++)    map2[a2[i]]++;
    string ans = "Yes";
    for(int i=0;i<m;i++)
        if(map2[a2[i]] != map1[a2[i]])
        {
            ans = "No";
            break;
        }
    return ans;
}