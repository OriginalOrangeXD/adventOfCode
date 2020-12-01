#include<iostream>
#include<fstream>
#include<vector>
#include<string>

int main(){
	std::fstream newfile;
	std::vector<int> nums;
	newfile.open("/home/robert/adventOfCode/day01/input.txt", std::ios::in);
	if(newfile.is_open()){
		std::string tp;
		while(getline(newfile, tp)){
			nums.push_back(std::stoi(tp));
		}
		newfile.close();
	}
	for(long unsigned int i = 0; i < nums.size(); i++)
	{
		for(long unsigned int x = i+1; x < nums.size(); x++)
		{
			for(long unsigned int y = x+1; y < nums.size(); y++)
			{
			if(nums[y] + nums[i] + nums[x] == 2020)
			{
				std::cout << nums[y]*nums[i]*nums[x];
			}
			}
		}
	}
}
