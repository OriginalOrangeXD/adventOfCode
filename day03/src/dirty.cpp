#include<iostream>
#include<fstream>
#include<vector>
#include<string>

int main()
{
	std::fstream newfile;
	std::vector<std::string> list;
	newfile.open("/home/robert/adventOfCode/day03/input.txt", std::ios::in);
	if(newfile.is_open()){
		std::string tp;
		while(getline(newfile, tp))
		{
			list.push_back(tp);
		}
		newfile.close();
	}
	long unsigned int pos1{3};
	long unsigned int pos{1};
	long unsigned int pos2{5};
	long unsigned int pos3{1};
	long unsigned int pos4{7};

	int totalTree{};
	int totalTree1{};
	int totalTree2{};
	int totalTree3{};
	int totalTree4{};
	for(unsigned long int i=1; (i < list.size()) && (list[i].size() >=pos); i++)
	{
		std::cout << list[i] << "\n";
		std::cout << list[i].substr(pos, 1);
		if(list[i].substr(pos, 1) == "#") totalTree++;
		pos++;
		pos = pos %31;
	}
	int tempTree = totalTree;
	for(unsigned long int i=1; (i < list.size()) && (list[i].size() >=pos1); i++)
	{
		std::cout << list[i] << "\n";
		std::cout << list[i].substr(pos1, 1);
		if(list[i].substr(pos1, 1) == "#") totalTree1++;
		pos1+=3;
		pos1 = pos1 %31;
	}
	totalTree*=totalTree1;	
	for(unsigned long int i=1; (i < list.size()) && (list[i].size() >=pos2); i++)
	{
		std::cout << list[i] << "\n";
		std::cout << list[i].substr(pos2, 1);
		if(list[i].substr(pos2, 1) == "#") totalTree2++;
		pos2+=5;
		pos2 = pos2 %31;
	}
	totalTree*=totalTree2;
	for(unsigned long int i=1; (i < list.size()) && (list[i].size() >=pos3); i+=2)
	{
		std::cout << list[i] << "\n";
		std::cout << list[i].substr(pos3, 1);
		if(list[i].substr(pos3, 1) == "#") totalTree3++;
		pos3++;
		pos3 = pos3 %31;
	}
	totalTree*=totalTree3;
	for(unsigned long int i=1; (i < list.size()) && (list[i].size() >=pos4); i++)
	{
		std::cout << list[i] << "\n";
		std::cout << list[i].substr(pos, 1);
		if(list[i].substr(pos4, 1) == "#") totalTree4++;
		pos4+=7;
		pos4 = pos4 %31;
	}
	std::cout << totalTree << "\n";
	std::cout << tempTree << "\n";
	std::cout << totalTree1 << "\n";
	std::cout << totalTree2 << "\n";
	std::cout << totalTree3 << "\n";
	std::cout << totalTree4 << "\n";
	std::cout << totalTree*totalTree4;
}
