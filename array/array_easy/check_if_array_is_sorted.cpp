#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool sortedArray(vector<int>& arr) {
	int i=0;
	while(i<arr.size())
	{
		if (arr[i]>arr[i+1])
		{
			return false;
		}
		i++;
	}
	return true;
}


int main() {
	vector<int> arr1 = {2, 5, 1, 3, 0};
	vector<int> arr2 = {11,12,13,14,15};
	
	bool ans=sortedArray(arr2);
	cout<<"The Array Is Sorted or Not: "<<ans<<endl;

	return 0;
}