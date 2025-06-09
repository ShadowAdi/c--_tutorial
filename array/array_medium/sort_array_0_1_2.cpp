#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortArrayBrute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums;
}


vector<int> sortArrayBetter(vector<int>& nums) {
    int zero_count = 0;
    int one_count = 0;
    int two_count = 0;

    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 0) {
            zero_count++;
        } else if(nums[i] == 1) {
            one_count++;
        } else {
            two_count++;
        }
    }

    for(int i = 0; i < zero_count; i++) {
        nums[i] = 0;
    }
    for(int i =zero_count ; i <zero_count+one_count ; i++) {
        nums[i] = 1;
    }
    for(int i = one_count+zero_count; i < nums.size(); i++) {
        nums[i] = 2;
    }

    return nums;
}

int main() {
    int n = 6;
    vector<int> arr = {0, 2, 1, 2, 0, 1};
    sortArrayBetter(arr);
    cout << "After sorting:" << endl;
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}