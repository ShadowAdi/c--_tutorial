#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// string twoSumBruteVariant1(int n, vector<int> ans, int target) {
//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(ans[i] + ans[j] == target) {
//                 return "YES";
//             }
//         }
//     }
//     return "NO";
// }

// vector<int> twoSumBruteVariant2(int n, vector<int> ans, int target) {
//     for(int i = 0; i < n; i++) {
//         for(int j = i + 1; j < n; j++) {
//             if(ans[i] + ans[j] == target) {
//                 return {i, j};
//             }
//         }
//     }
//     return {-1, -1};
// }


// vector<int> twoSumBetterVariant1(int n, vector<int> ans, int target) {
//     vector<int, int> hash_map;
//     for(int i = 0; i < n; i++) {
//         int complement = target - ans[i];
//         if(hash_map.find(complement) != hash_map.end()) {
//             return "Yes";
//         }
//         hash_map[ans[i]] = i;
//     }
//     return "No"
// }


// vector<int> twoSumBetterVariant2(int n, vector<int> ans, int target) {
//     vector<int, int> hash_map;
//     for(int i = 0; i < n; i++) {
//         int complement = target - ans[i];
//         if(hash_map.find(complement) != hash_map.end()) {
//             return {hash_map[complement], i};
//         }
//         hash_map[ans[i]] = i;
//     }
//     return {-1, -1};
// }



string twoSumOptimalVariant1(int n, vector<int> ans, int target) {
	sort(ans.begin(), ans.end());
	int left = 0;
	int right = n - 1;
	while(left < right) {
		int sum = ans[left] + ans[right];
		if(sum == target) {
			return "Yes";
		} else if(sum < target) {
			left += 1;
		} else {
			right -= 1;
		}
	}
	return "No";
}


vector<int> twoSumOptimalVariant2(int n, vector<int> ans, int target) {
	sort(ans.begin(), ans.end());
	int left = 0;
	int right = n - 1;
	while(left < right) {
		int sum = ans[left] + ans[right];
		if(sum == target) {
			return {left,right};
		} else if(sum < target) {
			left += 1;
		} else {
			right -= 1;
		}
	}
	return {-1,-1};
}

int main() {
	int n = 5;
	vector<int> arr = {2, 6, 5, 8, 11};
	int target = 14;
	vector<int> ans = twoSumOptimalVariant2(n, arr, target);
	for(auto& it:ans)
	{
		cout << "This is the answer for variant 1: " << it << endl;		
	}
	return 0;
}