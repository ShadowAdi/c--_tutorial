#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthLongestSubarray(vector<int> arr) {
	int n = arr.size();
	int max_len = 0;

	for(int i = 0; i < n; i++) {
		int curr_sum = 0;
		for(int j = i; j < n; j++) {
			curr_sum += arr[j];
			if(curr_sum == 0) {
				max_len = max(max_len, j - i + 1);
			}
		}
	}
	return max_len;
}

int lengthLongestSubarrayOptimal(vector<int> arr) {
	unordered_map<int, int> mpp;
	int n=arr.size();

	int maxi = 0;
	int summ = 0;
	for(int i = 0; i < n; i++) {
		summ += arr[i];
		if(summ == 0) {
			maxi = i + 1;
		} else {
			if(mpp.find(summ) != mpp.end()) {
				maxi = max(maxi, i - mpp[summ]);
			}else
			{
				mpp[summ]=i;
			}
		}
	}
	return maxi;
}

int main() {
	vector<int> a = {9, -3, 3, -1, 6, -5};
	cout << lengthLongestSubarrayOptimal(a) << endl;
	return 0;
}