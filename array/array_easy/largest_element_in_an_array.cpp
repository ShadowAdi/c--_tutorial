#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxSecondElement(vector<int>& arr) {
    int max = 0;
    int second_max = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] > second_max && arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if(arr[i] > second_max && arr[i] < max) {
            second_max = arr[i];
        }
    }
    return {max, second_max};
}

int main() {
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};
    vector<int> ans;
    ans = maxSecondElement(arr1);

    cout << "The Largest element in the array is: " << ans[0] << endl;
    cout << "The Second Largest element in the array is: " << ans[1] << endl;

    return 0;
}