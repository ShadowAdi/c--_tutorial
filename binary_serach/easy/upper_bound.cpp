
#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int> arr,int x,int n)
{
	for(int i=0;i<n;i++)
	{
		if (arr[i]>x)
		{
			return i;
		}
	}
	return n;
}

int upperBoundOptimal(vector<int> arr,int x,int n)
{
	int low=0;
	int ans=n;
	int high=n-1;
	while(low<=high)
	{
		int mid=(low+high)/2;
		if (arr[mid]>x)
		{
			ans=mid;
			high=mid-1;
		}else
		{
			low=mid+1;
		}
	}
	return ans;
}


int main()
{
	vector<int> arr = {3, 5, 8, 9, 15, 19};
	int n = 6, x = 9;
	int ind = upperBoundOptimal(arr, x, n);
	cout << "The upper bound is the index: " << ind << "\n";
	return 0;
}