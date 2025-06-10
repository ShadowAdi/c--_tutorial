#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int> arr)
{
	int maxP=0;
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if (arr[j]>arr[i])
			{
				maxP=max(maxP,arr[j]-arr[i]);				
			}
		}
	}
	return maxP;
}

int maxProfitOptimal(vector<int> arr)
{
	int maxPro=0;
	int n=arr.size();
	int min_price=INT_MAX;
	
	for(int i=0;i<n;i++)
	{
		min_price=min(min_price,arr[i]);
		maxPro=max(maxPro,arr[i]-min_price);
	}
	return maxPro;
}


int main()
{
	vector<int> arr = {7,1,5,3,6,4};
	int maxPro = maxProfit(arr);
	cout << "Max profit is: " << maxPro << endl;
	return 0;
}