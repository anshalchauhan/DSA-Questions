int binarySearch(vector<int>& arr,int start,int end,int target)
{
	if(start >= end)
		return (target > arr[start]) ? start + 1 : start;

	int mid = start + (end - start)/2;

	if(arr[mid] == target)	return mid;
	else if(arr[mid] > target)	return binarySearch(arr,start,mid-1,target);
	return binarySearch(arr,mid+1,end,target);
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
	if(arr.size() == 0) return ans;
	ans.push_back(arr[0]);
	int count = 1;

	// Insertion Sort
	for(int i=1;i<n;i++)
	{
		int key = arr[i];
		int j = i-1;

		int pos = binarySearch(arr,0,j,key);

		while(j>=pos)
		{
			arr[j+1] = arr[j];
			j--;
		}

		arr[j+1] = key;
		count++;

		if(count%2 != 0)	ans.push_back(arr[count/2]);
		else ans.push_back((arr[count/2 -1] + arr[count/2])/2);

	}
}