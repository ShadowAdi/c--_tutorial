#include <bits/stdc++.h>
using namespace std;

int  binarySearch(vector<int>& nums, int target) {
	int n = nums.size();
	int low = 0;
	int high = n - 1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(nums[mid] == target) {
			return mid;
		} else if(target > nums[mid]) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return -1;
}

int  binarySearchRecursive(vector<int>& nums, int low,int high,int target) {
	if (low>high)
	{
		return -1;
	}
	int mid=(low+high)/2;
	if (nums[mid]==target)
	{
		return mid;
	}else if(target>nums[mid])
	{
		return binarySearchRecursive(nums,mid+1,high,target);
	}else
	{
		return binarySearchRecursive(nums,low,mid-1,target);
	}
}

int search(vector<int>&  nums,int target)
{
	return binarySearchRecursive(nums,0,nums.size()-1,target);
}

int main() {
	vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
	int target = 6;
	int ind = search(a, target);
	if(ind == -1) cout << "The target is not present." << endl;
	else cout << "The target is at index: "
				  << ind << endl;
	return 0;
}