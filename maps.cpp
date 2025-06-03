#include <iostream>
#include <unordered_map>
#include <string>

void print(std::unordered_map<int,std::string> nums)
{
	for(auto i : nums)
	{
		std::cout<<"The Key is: "<<i.first<<" And The Value is: "<<i.second<<std::endl;
	}
}

int main()
{
	std::unordered_map<int,std::string> nums;
	std::unordered_map<int,std::string> num1={
		{1,"Greek"},
		{2,"Akshay"},
		{3,"Ak"}
	};
	
for(auto it=num1.begin();it!=num1.end();it++)
{
	 std::cout << it->first << ": " << it->second
        << std::endl;
}
	return 0;
}