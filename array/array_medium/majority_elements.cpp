#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int majorityElementBrute(vector<int> nums)
{
	int n=nums.size();
	int maxi=0;
	for(int i=0;i<n;i++)
	{
		int cCount=0;
		for(int j=i;j<n;j++)
		{
			if(nums[i]==nums[j])
			{
				cCount++;
				maxi=max(maxi,cCount);
			}
		}
	}
	return maxi;
}

int majorityElementBetter(vector<int> nums)
{
	unordered_map<int,int> hashMap;
	
	for(int i=0;i<nums.size();i++)
	{
		hashMap[nums[i]]++;
	}
	
	for(auto it:hashMap)
	{
		if (it.second>nums.size()/2)
		{
			return it.first;
		}
	} 
	return -1;
}


int majorityElementBest(vector<int> nums)
{
	int n=nums.size();
	
	int cnt=0;
	int el;
	
	for(int i=0;i<n;i++)
	{
		if(cnt==0)
		{
			cnt=1;
			el=nums[i];
		}
		else if (nums[i]==el)
		{
			cnt++;
		}
		else cnt-=1;
	}
	
	int cnt1=0;
	for(auto& it:nums)
	{
		if (it==el)
		{
			cnt1+=1;
		}
	}
	if (cnt1>n/2)
	{
		return el;
	}
}


int main() {
	 vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
	int ans = majorityElementBest(arr);
	cout << "The majority element is: " << ans << endl;
	return 0;	
}