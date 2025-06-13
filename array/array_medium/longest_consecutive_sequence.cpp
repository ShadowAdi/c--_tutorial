#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

bool linearSearch(vector<int> arr, int target) {
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] == target) {
			return true;
		}
	}
	return false;
}


int longestSuccessiveElementsBrute(vector<int> arr) {
	int n = arr.size();
	int maxLongest = 1;

	for(int i = 0; i < n; i++) {
		int x = arr[i];
		int cnt = 1;
		while(linearSearch(arr, x + 1) == true) {
			x += 1;
			cnt += 1;
		}
		maxLongest = max(cnt, maxLongest);
	}
	return maxLongest;
}

int longestSuccessiveElementsBetter(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int maxCnt = 1;
	int lastSmaller = INT_MIN;
	int currCnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] - 1 == lastSmaller) {
			currCnt += 1;
			lastSmaller = arr[i];
		} else if(arr[i] != lastSmaller) {
			currCnt = 1;
			lastSmaller = arr[i];
		}
		maxCnt = max(maxCnt, currCnt);
	}
	return maxCnt;
}

int longestSuccessiveElementsOptimal(vector<int> arr) {
	int n = arr.size();
	int longest = 1;
	unordered_set<int> st;

	for(int i = 0; i < n; i++) {
		st.insert(arr[i]);
	}

	for(auto it : st) {
		if(st.find(it - 1) != st.end()) {
			int cnt = 1;
			int x = it;
			while(st.find(x+1)!=st.end())
			{
				x=x+1;
				cnt+=1;
			}
			longest=max(longest,cnt);
		}
	}
	return longest;

}


int main() {
	vector<int> a = {100, 200, 1, 2, 3, 4};
	int ans = longestSuccessiveElementsOptimal(a);
	cout << "The longest consecutive sequence is " << ans << "\n";
	return 0;
}