#pragma once
#include <string>
#include <time.h>
#include <iostream>
using namespace std;
class Player
{
private :
	int Point;
	char Charector; 
	bool Computer = false;
	char Map[3][3] = { '0','0','0','0','0','0','0','0','0' };
public:
	
	char GetCharector()
	{
		return Charector;
	}
	Player(char ch,bool computer);
	int GetPoint()
	{
		return Point;
	}
	bool Winer()
	{
		if (Map[0][0] == Charector)
		{
			if (Map[0][1] == Charector && Map[0][2] == Charector)
			{
				Point++;
				return true;
			}
			if (Map[1][0] == Charector && Map[2][0] == Charector)
			{
				Point++;
				return true;
			}
			if (Map[1][1] == Charector && Map[2][2] == Charector)
			{
				Point++;
				return true;
			}
		}
		if (Map[0][2] == Charector)
		{
			if (Map[1][1] == Charector && Map[2][0] == Charector)
			{
				Point++;
				return true;
			}
			if (Map[1][2] == Charector && Map[2][2] == Charector)
			{
				Point++;
				return true;
			}
		}
		if (Map[0][1] == Charector && Map[1][1] == Charector && Map[2][1] == Charector)
		{
			Point++;
			return true;
		}
		else if (Map[1][0] == Charector && Map[1][1] == Charector && Map[1][2] == Charector)
		{
			Point++;
			return true;
		}
		else if (Map[2][0] == Charector && Map[2][1] == Charector && Map[2][2] == Charector)
		{
			Point++;
			return true;
		}
		return false;
	}

	void ss(char DoozMap[][3])
	{
		cout << DoozMap[2][0];
	}

	int Play(char DoozMap[][3], Player Ob2)
	{

		if (DoozMap[0][0] == Ob2.GetCharector() && DoozMap[0][1] == Ob2.GetCharector() && DoozMap[0][2] == '.')
		{
			Map[0][2] = Charector;
			return 3;
		}
		if (DoozMap[0][0] == Ob2.GetCharector() && DoozMap[0][2] == Ob2.GetCharector() && DoozMap[0][1] == '.')
		{
		Map[0][1] = Charector;
		return 2;
		}
		if (DoozMap[0][2] == Ob2.GetCharector() && DoozMap[0][1] == Ob2.GetCharector() && DoozMap[0][0] == '.')
		{
		Map[0][0] = Charector;
		return 1;
		}
		if (DoozMap[0][0] == Ob2.GetCharector() && DoozMap[1][0] == Ob2.GetCharector() && DoozMap[2][0] == '.')
		{
		Map[2][0] = Charector;
		return 7;
		}
		if (DoozMap[0][0] == Ob2.GetCharector() && DoozMap[2][0] == Ob2.GetCharector() && DoozMap[1][0] == '.')
		{
			cout << "yes";
		Map[1][0] = Charector;
		return 4;
		}
		if (DoozMap[2][0] == Ob2.GetCharector() && DoozMap[1][0] == Ob2.GetCharector() && DoozMap[0][0] == '.')
		{
		Map[0][0] = Charector;
		return 1;
		}
		if (DoozMap[2][2] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[0][0] == '.')
		{
		Map[0][0] = Charector;
		return 1;
		}
		if (DoozMap[0][0] == Ob2.GetCharector() && DoozMap[2][2] == Ob2.GetCharector() && DoozMap[1][1] == '.')
		{
		Map[1][1] = Charector;
		return 5;
		}
		if (DoozMap[0][0] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[2][2] == '.')
		{
		Map[2][2] = Charector;
		return 9;
		}
		if (DoozMap[2][1] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[0][1] == '.')
		{
		Map[0][1] = Charector;
		return 2;
		}
		if (DoozMap[2][1] == Ob2.GetCharector() && DoozMap[0][1] == Ob2.GetCharector() && DoozMap[1][1] == '.')
		{
		Map[1][1] = Charector;
		return 5;
		}
		if (DoozMap[0][1] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[2][1] == '.')
		{
		Map[2][1] = Charector;
		return 8;
		}
		if (DoozMap[2][2] == Ob2.GetCharector() && DoozMap[1][2] == Ob2.GetCharector() && DoozMap[0][2] == '.')
		{
		Map[0][2] = Charector;
		return 3;
		}
		if (DoozMap[2][2] == Ob2.GetCharector() && DoozMap[0][2] == Ob2.GetCharector() && DoozMap[1][2] == '.')
		{
		Map[1][2] = Charector;
		return 6;
		}
		if (DoozMap[0][2] == Ob2.GetCharector() && DoozMap[1][2] == Ob2.GetCharector() && DoozMap[2][2] == '.')
		{
		Map[2][2] = Charector;
		return 9;
		}
		if (DoozMap[2][0] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[0][2] == '.')
		{
		Map[0][2] = Charector;
		return 3;
		}
		if (DoozMap[2][0] == Ob2.GetCharector() && DoozMap[0][2] == Ob2.GetCharector() && DoozMap[1][1] == '.')
		{
		Map[1][1] = Charector;
		return 5;
		}
		if (DoozMap[0][2] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[2][0] == '.')
		{
		Map[2][0] = Charector;
		return 7;
		}
		if (DoozMap[2][0] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[0][2] == '.')
		{
		Map[0][2] = Charector;
		return 3;
		}
		if (DoozMap[1][2] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[1][0] == '.')
		{
		Map[1][0] = Charector;
		return 4;
		}
		if (DoozMap[1][2] == Ob2.GetCharector() && DoozMap[1][0] == Ob2.GetCharector() && DoozMap[1][1] == '.')
		{
		Map[1][1] = Charector;
		return 5;
		}
		if (DoozMap[1][0] == Ob2.GetCharector() && DoozMap[1][1] == Ob2.GetCharector() && DoozMap[1][2] == '.')
		{
		Map[1][2] = Charector;
		return 6;
		}
		if (DoozMap[2][1] == Ob2.GetCharector() && DoozMap[2][2] == Ob2.GetCharector() && DoozMap[2][0] == '.')
		{
		Map[2][0] = Charector;
		return 7;
		}
		if (DoozMap[2][0] == Ob2.GetCharector() && DoozMap[2][2] == Ob2.GetCharector() && DoozMap[2][1] == '.')
		{
		Map[2][1] = Charector;
		return 8;
		}
		if (DoozMap[2][1] == Ob2.GetCharector() && DoozMap[2][0] == Ob2.GetCharector() && DoozMap[2][2] == '.')
		{
		Map[2][2] = Charector;
		return 9;
		}
		if (DoozMap[0][0] == GetCharector() && DoozMap[0][1] == GetCharector() && DoozMap[0][2] == '.')
		{
			Map[1][0] = Charector;
			return 3;
		}
		if (DoozMap[0][0] == GetCharector() && DoozMap[0][2] == GetCharector() && DoozMap[0][1] == '.')
		{
			Map[0][1] = Charector;
			return 2;
		}
		if (DoozMap[0][2] == GetCharector() && DoozMap[0][1] == GetCharector() && DoozMap[0][0] == '.')
		{
			Map[0][0] = Charector;
			return 1;
		}
		if (DoozMap[0][0] == GetCharector() && DoozMap[1][0] == GetCharector() && DoozMap[2][0] == '.')
		{
			Map[2][0] = Charector;
			return 7;
		}
		if (DoozMap[0][0] == GetCharector() && DoozMap[2][0] == GetCharector() && DoozMap[1][0] == '.')
		{
			Map[1][0] = Charector;
			return 4;
		}
		if (DoozMap[2][0] == GetCharector() && DoozMap[1][0] == GetCharector() && DoozMap[0][0] == '.')
		{
			Map[0][0] = Charector;
			return 1;
		}
		if (DoozMap[2][2] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[0][0] == '.')
		{
			Map[0][0] = Charector;
			return 1;
		}
		if (DoozMap[0][0] == GetCharector() && DoozMap[2][2] == GetCharector() && DoozMap[1][1] == '.')
		{
			Map[1][1] = Charector;
			return 5;
		}
		if (DoozMap[0][0] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[2][2] == '.')
		{
			Map[2][2] = Charector;
			return 9;
		}
		if (DoozMap[2][1] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[0][1] == '.')
		{
			Map[0][1] = Charector;
			return 2;
		}
		if (DoozMap[2][1] == GetCharector() && DoozMap[0][1] == GetCharector() && DoozMap[1][1] == '.')
		{
			Map[1][1] = Charector;
			return 5;
		}
		if (DoozMap[0][1] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[2][1] == '.')
		{
			Map[2][1] = Charector;
			return 8;
		}
		if (DoozMap[2][2] == GetCharector() && DoozMap[1][2] == GetCharector() && DoozMap[0][2] == '.')
		{
			Map[0][2] = Charector;
			return 3;
		}
		if (DoozMap[2][2] == GetCharector() && DoozMap[0][2] == GetCharector() && DoozMap[1][2] == '.')
		{
			Map[1][2] = Charector;
			return 6;
		}
		if (DoozMap[0][2] == GetCharector() && DoozMap[1][2] == GetCharector() && DoozMap[2][2] == '.')
		{
			Map[2][2] = Charector;
			return 9;
		}
		if (DoozMap[2][0] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[0][2] == '.')
		{
			Map[0][2] = Charector;
			return 3;
		}
		if (DoozMap[2][0] == GetCharector() && DoozMap[0][2] == GetCharector() && DoozMap[1][1] == '.')
		{
			Map[1][1] = Charector;
			return 5;
		}
		if (DoozMap[0][2] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[2][0] == '.')
		{
			Map[2][0] = Charector;
			return 7;
		}
		if (DoozMap[2][0] == GetCharector() && DoozMap[1][1] == GetCharector() && DoozMap[0][2] == '.')
		{
			Map[0][2] = Charector;
			return 3;
		}
		if (DoozMap[1][2] == Charector && DoozMap[1][1] == Charector && DoozMap[1][0] == '.')
		{
			Map[1][0] = Charector;
			return 4;
		}
		if (DoozMap[1][2] == Charector && DoozMap[1][0] == Charector && DoozMap[1][1] == '.')
		{
			Map[1][1] = Charector;
			return 5;
		}
		if (DoozMap[1][0] == Charector && DoozMap[1][1] == Charector && DoozMap[1][2] == '.')
		{
			Map[1][2] = Charector;
			return 6;
		}
		if (DoozMap[2][1] == Charector && DoozMap[2][2] == Charector && DoozMap[2][0] == '.')
		{
			Map[2][0] = Charector;
			return 7;
		}
		if (DoozMap[2][0] == Charector && DoozMap[2][2] == Charector && DoozMap[2][1] == '.')
		{
			Map[2][1] = Charector;
			return 8;
		}
		if (DoozMap[2][1] == Charector && DoozMap[2][0] == Charector && DoozMap[2][2] == '.')
		{
			Map[2][2] = Charector;
			return 9;
		}
		else
		{
			do
			{
				srand(time(0));
				int x = (rand() % (3));
				srand(time(0)+1213);
				int y = (rand() % (3));
				if (DoozMap[x][y] == '.')
				{
					Map[x][y] = Charector;
					switch (x)
					{
					case 0 :
						switch (y)
						{
							case 0: return 0; break;
							case 1: return 1; break;
							case 2: return 3; break;
						}break;
					case 1:
						switch (y)
						{
						case 0: return 4; break;
						case 1: return 5; break;
						case 2: return 6; break;
						}break;
					case 2:
						switch (y)
						{
						case 0: return 7; break;
						case 1: return 8; break;
						case 2: return 9; break;
						}break;
					}
					break;
				}
			} while (true);
		}

	}

	bool Play(char DoozMap[][3],int xy)
	{
		switch (xy)
		{
		case 1:
			if (DoozMap[0][0] == '.')
			{
				Map[0][0] = Charector;
				return true;
			}
			break;
		case 2:
			if (DoozMap[0][1] == '.')
			{
				Map[0][1] = Charector;
				return true;
			}
			break;
		case 3:
			if (DoozMap[0][2] == '.')
			{
				Map[0][2] = Charector;
				return true;
			}
			break;
		case 4:
			if (DoozMap[1][0] == '.')
			{
				Map[1][0] = Charector;
				return true;
			}
			break;
		case 5:
			if (DoozMap[1][1] == '.')
			{
				Map[1][1] = Charector;
				return true;
			}
			break;
		case 6:
			if (DoozMap[1][2] == '.')
			{
				Map[1][2] = Charector;
				return true;
			}
			break;
		case 7:
			if (DoozMap[2][0] == '.')
			{
				Map[2][0] = Charector;
				return true;
			}
			break;
		case 8:
			if (DoozMap[2][1] == '.')
			{
				Map[2][1] = Charector;
				return true;
			}
			break;
		case 9:
			if (DoozMap[2][2] == '.')
			{
				Map[2][2] = Charector;
				return true;
			}
			break;
		default:
			return false;
			break;
		}
	}

	void RestartGame()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				Map[i][j] = '0';
			}
		}
	}

};

