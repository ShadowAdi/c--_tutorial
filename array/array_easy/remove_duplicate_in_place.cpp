#include <iostream>
#include <vector>
#include <set>
using namespace std;

int removeDuplicates(vector<int>& arr, int n) {
    set<int> newSet(arr.begin(), arr.end());
    arr.clear(); // Clear original vector
    for(int val : newSet) {
        arr.push_back(val); // Add unique values back
    }
    return arr.size();
}

int removeDuplicatesTwoPointer(vector<int>& arr, int n) {
    int i = 0;
    for(int j = 1; j < arr.size(); j++) {
        if(arr[j] != arr[i]) {
			i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}


int main() {
    vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
    int n = arr.size();
    int k = removeDuplicatesTwoPointer(arr, n);

    cout << "After removing duplicates: ";
    for(int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The Value of K is: " << k << endl;

    return 0;
}
