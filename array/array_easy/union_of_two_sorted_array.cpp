#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

vector<int> FindUnion(vector<int>& arr1, vector<int>& arr2) {
	arr1.insert(arr1.end(), arr2.begin(), arr2.end());
	set<int> array_set(arr1.begin(), arr1.end());
	vector<int> ans(array_set.begin(), array_set.end());
	return ans;
}

vector<int> FindUnion2(vector<int>& arr1, vector<int>& arr2) {
	map<int, int> freq;
	vector<int> Union;
	for(int i = 0; i < arr1.size(); i++) {
		freq[arr1[i]]++;
	}
	for(int j = 0; j < arr2.size(); j++) {
		freq[arr2[j]]++;
	}
	for(auto& it : freq) {
		Union.push_back(it.first);
	}
	return Union;
}


vector<int> FindUnion3(vector<int>& arr1, vector<int>& arr2) {
	int i=0, j = 0;
	vector<int> Union;
	while(i < arr1.size() && j < arr2.size()) {
		if(arr1[i] <= arr2[j]) {
			if(Union.size() == 0 || Union.back() != arr1[i]) {
				Union.push_back(arr1[i]);
			}
			i++;
		} else {
			if(Union.size() == 0 || Union.back() != arr2[j]) {
				Union.push_back(arr2[j]);
			}
			j++;
		}
	}
	while(i < arr1.size()) {
		if(Union.back() != arr1[i]) {
			Union.push_back(arr1[i]);
			i++;
		}
	}
	while(j < arr2.size()) {
		if(Union.back() != arr2[j]) {
			Union.push_back(arr2[j]);
			j++;
		}
	}
	return Union;
}




int main() {
	vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
	vector<int> Union = FindUnion3(arr1, arr2);
	cout << "Union of arr1 and arr2 is " << endl;
	for(auto & val : Union)
		cout << val << " ";
	return 0;
}