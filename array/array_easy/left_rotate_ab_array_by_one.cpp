#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leftRotate(vector<int>& nums, int n) {
    int k = nums[0];
    int j = 1;
    while(j < n) {
        nums[j - 1] = nums[j];
        j++;
    }
    nums[n - 1] = k;
    return nums;
}

vector<int> leftRotateByD(vector<int>& nums, int n, int d) {
    while(d > 0) {
        int k = nums[0];
        int j = 1;
        while(j < n) {
            nums[j - 1] = nums[j];
            j++;
        }
        nums[n - 1] = k;
        d -= 1;
    }
    return nums;
}

void leftRotateByDOptimized(vector<int>& nums, int n, int d) {
    if(n == 0) return;
    d = d % n;
    reverse(nums.begin(), nums.begin() + d);
    reverse(nums.begin() + d, nums.end());
    reverse(nums.begin(), nums.end());
}



int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    leftRotateByDOptimized(arr, n, 3);
    for(int num : arr) {
        cout << "The Value of num is: " << num << endl;
    }
    return 0;
}
