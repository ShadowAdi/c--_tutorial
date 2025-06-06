#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> FindUnion(vector<int>& arr1,vector<int>& arr2)
{
	arr1.insert(arr1.end(),arr2.begin(),arr2.end());
	set<int> array_set(arr1.begin(),arr1.end());
	vector<int> ans(array_set.begin(),array_set.end());
	return ans;
}

// vector<int> FindUnion2(vector<int> arr1,vector<int> arr2)
// {
// 	map<int,int> freq;
// 	vector<int> Union;
	
// }

int main() {
	vector<int> arr1= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> arr2= {2, 3, 4, 4, 5, 11, 12};
	vector<int> Union = FindUnion(arr1, arr2);
	cout << "Union of arr1 and arr2 is " << endl;
	for(auto & val : Union)
		cout << val << " ";
	return 0;
}