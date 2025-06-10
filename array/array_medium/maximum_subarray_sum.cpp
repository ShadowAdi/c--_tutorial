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


int maxSubarrayOptimal(vector<int> nums, int n) {
    long long maxi = LONG_MIN;
    long long summ = 0;

    for(int i = 0; i < n; i++) {
        summ += nums[i];
        if(summ > maxi) {
            maxi = summ;
        }
        if(summ < 0) {
            summ = 0;
        }
    }
    return maxi;
}



void maxSubarrayVraiation(vector<int> nums, int n) {
    int currSem = 0;
    int maxSum = INT_MIN;
    int start = 0;
    int tempStart = 0;
    int end = 0;

    for(int i = 0; i < n; i++) {
        currSem += nums[i];
        if(currSem > maxSum) {
            maxSum = currSem;
            start = tempStart;
            end = i;
        }
        if(currSem < 0) {
            currSem = 0;
            tempStart = i - 1;
        }
    }

    cout << "Maximum Subarray Sum: " << maxSum << endl;
    cout << "Subarray: [ ";
    for(int i = start; i <= end; i++) {
        cout << nums[i] << " ";
    }
    cout << "]" << endl;
}



int main() {
    vector<int> arr = { -2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = arr.size();
    maxSubarrayVraiation(arr,n);
    return 0;
}