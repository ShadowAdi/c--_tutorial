#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getLongestSubarray(vector<int> a, int k) {
	int n = a.size();
	int len = 0;
	for(int i = 0; i < n; i++) {
		long long summ = 0;
		for(int j = i; j < n; j++) {
			summ += a[j];
			if(summ == k) {
				len = max(len, j - i + 1);
			}
		}
	}
	return len;
}

int getLongestSubarrayHsshing(vector<int> a, int k) {
	int n = a.size();
	map<long long, int> preSumMap;
	long long sum = 0;
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		sum += a[i];
		if(sum == k) {
			maxLen = max(maxLen, i + 1);
		}


		long long rem = sum - k;
		if(preSumMap.find(rem) != preSumMap.end()) {
			int len = i - preSumMap[rem];
			maxLen = max(maxLen, len);
		}

		if(preSumMap.find(sum) == preSumMap.end()) {
			preSumMap[sum] = i;
		}
	}
	return maxLen;
}


int getLongestSubarrayOptimnal(vector<int> a, int k) {
	int n = a.size();
	int left=0,right=0;
	long long sum=a[0];
	int maxLen=0;
	while (right<n)
	{
		while(left<=right && sum>k)
		{
			sum-=a[left];
			left++;
		}
		if (sum==k)
		{
			maxLen=max(maxLen,right-left+1);
		}
		right++;
		if (right<n)
		{
			sum+=a[right];
		}
	}
	return maxLen;
}



int main() {
	vector<int> a = {2, 3, 5, 1, 9};
	long long k = 10;
	int len = getLongestSubarrayOptimnal(a, k);
	cout << "The length of the longest subarray is: " << len << "\n";
	return 0;
}