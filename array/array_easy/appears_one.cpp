#include <iostream>
#include <vector>
#include <map>
using namespace std;

int getSingleElement(vector<int> arr) {
    map<int, int> nums;
    for(int i = 0; i < arr.size(); i++) {
        nums[arr[i]]++;
    }
    for(auto& it : nums) {
        if(it.second == 1) {
            cout << "Got  it: " << it.first << " " << it.second << "\n";
            return it.first;
        }
    }
}

int getSingleElementHashing(vector<int> arr) {
    int n = arr.size();
    int maxi = arr[0];
    for(int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi + 1, 0);
    for(int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        if(hash[arr[i]] == 1) {
            return arr[i];
        }
    }
    return -1;
}


int getSingleElementXOR(vector<int> arr) {
    int n = arr.size();
    int xorr = 0;
    for(int i = 0; i < arr.size(); i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}


int main() {
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElementXOR(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}