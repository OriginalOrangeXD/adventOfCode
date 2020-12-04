#include<bits/stdc++.h>
#include<fstream>
#include<map>

int treesHit(int slopeX, int slopeY, char map[323][31])
{
	int posX{0};
	int posY{0};
	int tree{};
	while(posY<323)
	{

		if(map[posY][posX] == '#') tree++;
		posY += slopeY;
		posX=(posX+ slopeX) % 31;
	}
	return tree;
}


int main ()
{
	std::fstream newfile;
	char hill[323][31];
	newfile.open("/home/robert/adventOfCode/day03/input.txt", std::ios::in);
	if(newfile.is_open())
	{
		int i{};
		std::string tp;
		while(getline(newfile, tp))
		{
			std::strcpy(hill[i], tp.c_str());
			i++;
		}
	}
	long tmp{treesHit(1,1,hill)};
	tmp *=treesHit(3,1,hill);

	std::cout << tmp << "\n";
	tmp *= treesHit(5,1,hill);
	tmp *=treesHit(7,1,hill);
	tmp *=treesHit(1,2,hill);
	std::cout << tmp;
	/*
	for(int i = 0; i < 323; i++)
	{
		for(int x=0; x<31;x++)
		{
			std::cout << hill[i][x];
		}
		std::cout << "\n";
	}
	*/
}

			 
