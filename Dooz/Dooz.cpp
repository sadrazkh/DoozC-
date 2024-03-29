#include "pch.h"
#include <iostream>
#include <cstdlib>   
#include <stdlib.h>  
#include <fstream>
#include <string>
#include "Player.h"
//#include <cstdlib>

using namespace std;

char DoozMap[3][3] = { '1','2','3','4','5','6','7','8','9' };
char Map[3][3] = { '.','.','.','.','.','.','.','.','.' };


void MapPrint(Player ob1,Player ob2)
{
	cout << "\n\n\n";
	cout << "player One : " << ob1.GetPoint() << "\tplayer Two : " << ob2.GetPoint()<<"\n\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == '.')
			{
				cout << DoozMap[i][j];
			}
			else
			{
				cout << Map[i][j];
			}
			if (j != 2)
				cout<< "|";
		}
		if (i != 2)
		{
			cout << "\n_____";
		}
		cout << '\n';
	}
	cout << "\n\n";
}


void RestartGame()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Map[i][j] = '.';
		}
	}
}

bool Same()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Map[i][j] == '.')
			{
				return false;
				break;
			}
		}
	}
	return true;
}


int main()
{
	int ColorNum = 0;
    cout << "\t\t\t\tTic Tac Toe Game!\n\n\n";
	
	ifstream Save("Save.txt");
	if (Save)
	{
		Save >> ColorNum;
		Save.close();
	}
	else if (!Save)
	{
		cout << "Please Select Color : \n0.Defualt\n1.Black & Red\n2.Black & Green\n3.Black & Yellow\n4.White & Pink";
		cin >> ColorNum;
		ofstream Save("Save.txt");
		Save << ColorNum;
		Save.close();
	}
	switch (ColorNum)
	{
	case 1:
		system("color 04");
		break;
	case 2:
		system("color 02");
		break;
	case 3:
		system("color 0E");
		break;
	case 4:
		system("color FD");
		break;
	default:
		break;
	}
	system("cls");
	string mod;
	int Mod;
	cout << "Please Select Your Mod : \n0.Multiplay\n1.Play whit Computer\n";
	cin >> mod;
	try
	{
		Mod = stoi(mod);
	}
	catch (const std::exception)
	{
		cerr << "Your action not Valid !";
		exit(0);
	}
	bool Co = false;
	switch (Mod)
	{
	case 0:break;
	case 1:Co = true; break;
	default:		
		cerr << "Your action not Valid !";
		exit(0);
	}
	char CharOne , CharTwo;
	cout << "Please Enter Player One Cahrector : ";
	cin >> CharOne;
	cout << "Please Enter Player Two Cahrector : ";
	cin >> CharTwo;
	if (CharTwo == CharOne)
	{
		cerr << "both of charector is same!";
		exit(0);
	}
	Player PlayerOne(CharOne, false);
	Player PlayerTwo(CharTwo, Co);


	int xy = 0;
	srand(time(0));
	int ran = rand() % 2;
	bool GoOne = true;

	do
	{
		system("cls");
		MapPrint(PlayerOne, PlayerTwo);

		if (ran%2 == 0)
		{

			do
			{
				cout << "Player One Select Number : ";
				cin >> xy;
				if (PlayerOne.Play(Map, xy))
				{
					switch(xy)
					{
					case 1:
						if (Map[0][0] == '.')
						{
							Map[0][0] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 2:
						if (Map[0][1] == '.')
						{
							Map[0][1] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 3:
						if (Map[0][2] == '.')
						{
							Map[0][2] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 4:
						if (Map[1][0] == '.')
						{
							Map[1][0] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 5:
						if (Map[1][1] == '.')
						{
							Map[1][1] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 6:
						if (Map[1][2] == '.')
						{
							Map[1][2] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 7:
						if (Map[2][0] == '.')
						{
							Map[2][0] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 8:
						if (Map[2][1] == '.')
						{
							Map[2][1] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					case 9:
						if (Map[2][2] == '.')
						{
							Map[2][2] = PlayerOne.GetCharector();
							GoOne = false;
						}
						break;
					}	
				}

			} while (GoOne);

			if (!PlayerOne.Winer())
			{
				if (Same())
				{
					PlayerOne.RestartGame();
					PlayerTwo.RestartGame();
					RestartGame();
				}
				ran++;
			}
			else
			{
				PlayerOne.RestartGame();
				PlayerTwo.RestartGame();
				RestartGame();
			}
			GoOne = true;
		}
		else
		{
			if (!Co)
			{

				do
				{
					cout << "Player Two Select Number : ";
					cin >> xy;
					if (PlayerTwo.Play(Map, xy))
					{
						switch (xy)
						{
						case 1:
							if (Map[0][0] == '.')
							{
								Map[0][0] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 2:
							if (Map[0][1] == '.')
							{
								Map[0][1] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 3:
							if (Map[0][2] == '.')
							{
								Map[0][2] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 4:
							if (Map[1][0] == '.')
							{
								Map[1][0] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 5:
							if (Map[1][1] == '.')
							{
								Map[1][1] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 6:
							if (Map[1][2] == '.')
							{
								Map[1][2] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 7:
							if (Map[2][0] == '.')
							{
								Map[2][0] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 8:
							if (Map[2][1] == '.')
							{
								Map[2][1] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						case 9:
							if (Map[2][2] == '.')
							{
								Map[2][2] = PlayerTwo.GetCharector();
								GoOne = false;
							}
							break;
						}
					}
				} while (GoOne);
				GoOne = true;
			}
			else
			{
				xy = PlayerTwo.Play(Map, PlayerOne);
				switch (xy)
				{
				case 1:
					if (Map[0][0] == '.')
					{
							Map[0][0] = PlayerTwo.GetCharector();
					}
					break;
				case 2:
					if (Map[0][1] == '.')
					{
						Map[0][1] = PlayerTwo.GetCharector();
					}
					break;
				case 3:
					if (Map[0][2] == '.')
					{
						Map[0][2] = PlayerTwo.GetCharector();
					}
					break;
				case 4:
					if (Map[1][0] == '.')
					{
						Map[1][0] = PlayerTwo.GetCharector();
					}
					break;
				case 5:
					if (Map[1][1] == '.')
					{
						Map[1][1] = PlayerTwo.GetCharector();
					}
					break;
				case 6:
					if (Map[1][2] == '.')
					{
						Map[1][2] = PlayerTwo.GetCharector();
					}
					break;
				case 7:
					if (Map[2][0] == '.')
					{
						Map[2][0] = PlayerTwo.GetCharector();
					}
					break;
				case 8:
					if (Map[2][1] == '.')
					{
						Map[2][1] = PlayerTwo.GetCharector();
					}
					break;
				case 9:
					if (Map[2][2] == '.')
					{
						Map[2][2] = PlayerTwo.GetCharector();
					}
				}
			}

			if (!PlayerTwo.Winer())
			{
				if (Same())
				{
					PlayerOne.RestartGame();
					PlayerTwo.RestartGame();
					RestartGame();
				}
				ran++;
			}
			else
			{
				PlayerOne.RestartGame();
				PlayerTwo.RestartGame();
				RestartGame();
			}
			
		}
	}while (true);

}