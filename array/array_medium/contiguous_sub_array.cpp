#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int findAllSubarraysWithGivenSum(vector<int> arr, int k) {
	int n = arr.size();
	int cnt = 0;

	for(int i = 0; i < n; i++) {
		int sum = 0;
		for(int j = i; j < n; j++) {
			sum += arr[j];
			if(sum == k) {
				cnt++;
			}
		}
	}
	return cnt;
}

int findAllSubarraysWithGivenSumOptimal(vector<int> arr, int k) {
	int n = arr.size();
	int cnt = 0;
	unordered_map<int,int> mpp;
	int preSum=0;
	mpp[0]=1;
	for(int i=0;i<n;i++)
	{
		preSum+=arr[i];
		int remove=preSum-k;
		cnt+=mpp[remove];
		mpp[preSum]++;
	}
	return cnt;
}

int main() {
	vector<int> arr = {3, 1, 2, 4};
	int k = 6;
	int cnt = findAllSubarraysWithGivenSumOptimal(arr, k);
	cout << "The number of subarrays is: " << cnt << "\n";
	return 0;
}