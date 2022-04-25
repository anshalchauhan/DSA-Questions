int minimumSum (vector<int>& arr, int n)
{
   	int sum = 0;
	int min1 = arr[0];
	for(int i=0;i<n;i++)
	{
		sum += arr[i];
		if(sum < min1) min1 = sum;
		if(sum > 0) sum = 0;
	}
	return min1;
}