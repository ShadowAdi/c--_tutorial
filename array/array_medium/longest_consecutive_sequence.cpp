#include <iostream>
#include <vector>
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


int main() {
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElementsBrute(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}