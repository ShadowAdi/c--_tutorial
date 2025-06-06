#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> bruteMoveZeros(int n, vector<int> arr) {
    vector<int> temp;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] != 0) {
            temp.push_back(arr[i]);
        }
    }

    int nz = temp.size();

    for(int i = 0; i < nz; i++) {
        arr[i] = temp[i];
    }

    for(int i = nz; i < n; i++) {
        arr[i] = 0;
    }
    return arr;
}

void optimalMoveZeros(int n, vector<int>& arr) {
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] != 0) {
            if(i != j) {
                swap(arr[i], arr[j]);
            }
            j++;
        }
    }
}


int main() {
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int n = arr.size();
    optimalMoveZeros(n, arr);
    for(auto &it : arr) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}