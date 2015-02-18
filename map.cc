#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void vectorize_hash(map<string,int>& map,vector<string>& names, vector<int>& scores)
	{
		/*vector<string> names;
		vector<int> scores;*/

		int i = 0;
		for (auto o : map)
			{
		
				//cout << o.first;
				//cout << " => "<< o.second<<endl;
				names.push_back(o.first);
				scores.push_back(o.second);
			}

		//vector<vector> vectores(names,scores);

			//return vectores;
	}


void print_scoreboard(vector<int> v1, vector<string> v2)
	{
		int i;

		int tam = v1.size();
		cout << "--------------------" <<endl;
		for (i = 0 ; i < tam ; i++)
			{
				cout << v2[i] << " => " << v1[i]<<endl; 
			}
		cout << "--------------------" <<endl;
	}


void  addplayer_points(string nickname,int amount,map<string,int>& map)
	{
			map[nickname] += amount;	
	}

void initialize_scoreboard()
	{
		map<string,int> players;
		//vector<vectors> vectores;
		
		//vector<int> vect1 = {4,7,5,8,3,6,2};
		//vector<string> vect2 = {"gabriel","steven","darwin","carlos","andres","pepito","benito"};
		vector<int> vect1;
		vector<string> vect2;
		
		vectorize_hash(players,vect2,vect1);
		
		/*for(auto j: vectores)
			{
				for (auto k: j)
				{	
					cout<<k<<endl	
				}
			}
		*/


///PRINT SCORE BOARD
		print_scoreboard(vect1,vect2);
		
		
		int i;
		int mayor = vect1[0];
		int index = 0;
		int tam = vect1.size();
		for (i = 1 ; i < tam ; i++)
			{
				if(mayor > vect1[i])
					{
						mayor = mayor;
						//cout << "if" << endl;
						//cout << mayor << endl;
					}
				else
					{
						mayor = vect1[i];
						index = i;
						//cout << "else" << endl;
						//cout << mayor  << endl;
					}
			}
		//cout << "mayor:" << endl;
		
		//cout << "winner index:" << endl;
		//cout << index << endl;
		cout << "CURRENT SUDOKU MASTER" << endl;
		cout << vect2[index] <<": " << mayor << endl;		
		//cout << mayor << endl;
	}

int main()
	{
		initialize_scoreboard();
		addplayer_points("stiven",1,players);
		addplayer_points("gabriel",1,players);
		addplayer_points("gabriel",1,players);
		addplayer_points("gabriel",1,players);
		addplayer_points("B",1,players);

	}
