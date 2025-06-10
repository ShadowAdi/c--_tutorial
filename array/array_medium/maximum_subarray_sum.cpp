#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int maxSubarraySum(vector<int> nums, int n) {
	int maxi = INT_MIN;
	for(int i = 0; i < n; i++) {
		int summ = 0;
		for(int j = i; j < n; j++) {
			summ = summ + nums[j];
			maxi = max(summ, maxi);
		}
	}
	return maxi;
}


int maxSubarrayOptimal(vector<int> nums,int n)
{
	long long maxi=LONG_MIN;
	long long summ=0;

	for(int i=0;i<n;i++)
	{
		summ+=nums[i];
		if (summ>maxi)
		{
			maxi=summ;
		}
		if (summ<0)
		{
			summ=0;
		}
	}
	return maxi;	
}



int main() {
	vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = arr.size();
	int maxSum = maxSubarrayOptimal(arr, n);
	cout << "The maximum subarray sum is: " << maxSum << endl;
	return 0;
}