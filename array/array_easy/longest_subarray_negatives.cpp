#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getLongestSubarray(vector<int> a, int k) {
	int n = a.size();
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int s=0;
			for(int l = i; l <= j; l++) {
				s += a[l];
			}
			if(s == k) {
				maxLen = max(maxLen, j - i + 1);
			}
		}
	}
	return maxLen;
}

int getLongestSubarrayBetter(vector<int> a, int k) {
	int n = a.size();
	int maxLen = 0;
	for(int i = 0; i < n; i++) {
		int summ=0;
		for(int j = i; j < n; j++) {
			summ+=a[j];
			if (summ==k)
			{
				maxLen=max(maxLen,j-i+1);
			}
		   
		}
	}
	return maxLen;
}


int getLongestSubarrayOptimal(vector<int>& a, int k) {
	int n = a.size();
	map<int,int> preSumMap;
	int sum=0;
	int maxLen=0;
	
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
		if (sum==k)
		{
			maxLen=max(maxLen,i+1);
		}
		
		int rem=sum-k;
		
		if (preSumMap.find(rem)!=preSumMap.end())
		{
			int len=i-preSumMap[rem];
			maxLen=max(maxLen,len);
		}
		
		if (preSumMap.find(sum) == preSumMap.end())
		{
			preSumMap[sum]=i;
		}
	}
	return maxLen;
}


int main() {
	vector<int> a = { -1, 1, 1};
	int k = 1;
	int len = getLongestSubarrayOptimal(a, k);
	cout << "The length of the longest subarray is: " << len << "\n";
	return 0;
}
