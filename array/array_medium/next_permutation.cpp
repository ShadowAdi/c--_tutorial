#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums, int n) {
    int globalIndex = -1;
    for(int i = n - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            globalIndex = i;
            break;
        }
    }

    if(globalIndex == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    for(int i = n - 1; i > globalIndex; i--) {
        if(nums[i] > nums[globalIndex]) {
            swap(nums[i], nums[globalIndex]);
            break;
        }
    }

    reverse(nums.begin() + globalIndex + 1, nums.end());

}

int main() {

    vector<int> A = {2, 1, 5, 4, 3, 0, 0};
    int n = A.size();
    nextPermutation(A, n);
    for(int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    return 0;
}