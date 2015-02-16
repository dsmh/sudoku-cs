#include <string>
#include <iostream>
#include <map>

using namespace std;

void find_winner(map<string,int> map)
	{
		
	}


void  addplayer_points(string nickname,int amount,map<string,int> map)
	{
			map[nickname] += amount;	
	}

int main()
	{
		map<string,int> players;
		addplayer_points("stiven",1,players);
		addplayer_points("gabriel",-1,players);
		addplayer_points("B",1,players);
		players["C"] = -2;
		players["D"] = 3;
		players["E"] = -4;
		players["F"] = 5;

		//addplayer("C",2,players);
		//addplayer("D",3,players);
		//addplayer("F",4,players);


		cout <<players["gabriel"]<< endl;
		cout <<players["B"]<< endl;
		cout <<players["C"]<< endl;
		cout <<players["E"]<< endl;
		cout <<players["F"]<< endl;

	}