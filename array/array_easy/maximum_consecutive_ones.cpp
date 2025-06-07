#include <iostream>
#include <vector>
using namespace std;

int maxConsecutiveOnes(vector<int> nums) {
    int max_one_count = 0;
    int cnt = 0;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] == 1) {
            cnt += 1;
        } else {
            cnt = 0;
        }
        max_one_count = max(max_one_count, cnt);
    }
    return max_one_count;
}

int main() {
    vector < int > nums = { 1, 1, 0, 1, 1, 1 };
    int ans = maxConsecutiveOnes(nums);
    cout << "The maximum  consecutive 1's are " << ans;

    return 0;
}