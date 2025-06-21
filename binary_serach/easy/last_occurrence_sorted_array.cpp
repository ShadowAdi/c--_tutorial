#include <bits/stdc++.h>
using namespace std;

int bruteMethod(vector<int>& arr, int x) {
	int n = arr.size();
	int res = -1;
	for(int i = n - 1; i >= 0; i--) {
		if(arr[i] == x) {
			res = i;
			break;
		}

	}
	return res;
}

int optimalMethod(vector<int>& arr, int x) {
	int n = arr.size();
	int res = -1;
	int low = 0;
	int high = n - 1;
	while(low <= high) {
		int mid = (low + high) / 2;
		if(arr[mid] == x) {
			res = mid;
			low = mid + 1;
		} else if(x < arr[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	return res;
}

int main() {
	int key = 13;
	vector <int> v = {3, 4, 13, 13, 13, 20, 40};

	cout << optimalMethod(v, key) << "\n";

	return 0;
}