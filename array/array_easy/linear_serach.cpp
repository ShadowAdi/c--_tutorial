#include <iostream>
#include <vector>
using namespace std;


int linear_search(int n, vector<int> arr, int target) {
	for(int i = 0; i< n; i++) {
		if(arr[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	vector<int> arr = {1, 2, 3, 4, 5};
	int target = 4;
	int n =arr.size();
	int val = linear_search(n,arr,target);
	cout<<"The Value of val is: "<<val;
	return 0;
}