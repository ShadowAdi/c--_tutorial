#include <iostream>
#include <vector>
using namespace std;

void RearrangebySignBrute(vector<int>& nums, int n) {
	vector<int> pos;
	vector<int> neg;

	for(int i = 0; i < n; i++) {
		if(nums[i] > 0) {
			pos.push_back(nums[i]);
		} else {
			neg.push_back(nums[i]);
		}
	}
	vector<int> ans;
	for(int i = 0; i < n / 2; i++) {
		nums[2 * i] = pos[i];
		nums[2 * i + 1] = neg[i];
	}
}

vector<int> RearrangebySignOptimal(vector<int>& nums, int n) {
	int posIndex = 0;
	int negIndex = 1;
	vector<int> ans(n);

	for(int i = 0; i < n; i++) {
		if(nums[i] < 0) {
			ans[negIndex] = nums[i];
			negIndex += 2;
		} else {
			ans[posIndex] = nums[i];
			posIndex += 2;
		}
	}
	return ans;
}


int main() {

	vector<int> A {1, 2, -4, -5, 3, 4};
	int n = A.size();
	RearrangebySignOptimal(A, n);
	for(int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	return 0;
}