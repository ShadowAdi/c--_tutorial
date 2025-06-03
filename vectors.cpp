#include <iostream>
#include <vector>
#include <unordered_map>
using std::vector;
#include <set>
using std::set;
using namespace std;

vector<int> TwoNumbers(vector<int> nums, int target, int method) {

	if(method == 1) {
		for(int i = 0; i < nums.size(); i++) {
			for(int j = i + 1; j < nums.size(); j++) {
				if(nums[i] + nums[j] == target) {
					return vector<int> {i, j};
				}
			}
		}
		return vector<int> {0, 0};
	} else {
		std::unordered_map<int, int> complements;
		for(int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			if(complements.count(complement)) {
				return {complements[complement], i};
			}
			complements[nums[i]] = i;
		}
		return {};
	}
}

int sortedDataStructure(vector<int>& nums) {
	set<int> mySet(nums.begin(), nums.end());
	nums.assign(mySet.begin(), mySet.end());
	return nums.size();
}

int countUnique(vector<int> nums) {
	int i = 0;
	for(int j = 1; j < nums.size(); j++) {
		if(nums[i] != nums[j]) {
			i++;
		}
	}
	return i + 1;
}

void merge(long long arr1[], long long arr2[], int n, int m) {
	long long arr3[n + m];
	int left = 0;
	int right = 0;
	int index = 0;

	while(left < n && right < m) {
		if(arr1[left] <= arr2[right]) {
			arr3[index] = arr1[left];
			left++, index++;
		} else {
			arr3[index] = arr2[right];
			righht++, index++;
		}
	}
	while(left < n) {
		arr3[index + 1] = arr1[left++];
	}
	while[right < n] {
		arr3[index + 1] = arr2[right++];
	}
	for(int i = 0; i < n + m; i++) {
		if(i < n)
			arr1[i] = arr3[i];       // First n elements go into arr1
		else
			arr2[i - n] = arr3[i];   // Remaining m elements go into arr2
	}

}

int main() {
	long long arr1[] = {1, 4, 8, 10};
	long long arr2[] = {2, 3, 9};
	int n = 4, m = 3;
	merge(arr1, arr2, n, m);
	cout << "The merged arrays are: " << "\n";
	cout << "arr1[] = ";
	for(int i = 0; i < n; i++) {
		cout << arr1[i] << " ";
	}
	cout << "\narr2[] = ";
	for(int i = 0; i < m; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;

	return 0;
}