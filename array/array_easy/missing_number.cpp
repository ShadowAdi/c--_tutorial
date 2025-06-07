#include <iostream>
#include <vector>
using namespace std;

int add_number(vector<int>& nums) {
	int arraySum = 0;
	for(int i = 0; i < nums.size()-1; i++) {
		arraySum += nums[i];
	}
	int summ=(nums.size()*(nums.size()+1))/2;
	return summ-arraySum;
}

int xor_approach(vector<int>& nums) {
	int xor1=0,xor2=0;
	for(int i=0;i<nums.size()-1;i++)
	{
		xor2=xor2^nums[i];
		xor1=xor1^(i+1);
	}
	xor1=xor1^nums.size();
	return xor1^xor2;
}


int main() {
	vector<int> a = {1, 2, 4, 5};
	int ans = xor_approach(a);
	cout << "The missing number is: " << ans << endl;
	return 0;
}