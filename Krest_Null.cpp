#include <iostream>
#include <random>
#include <cmath>
#include <ctime>

enum tic_tac_toe_field : uint8_t
{
	X = 88, O = 79, N = 32  		//Крестик, нолик или пустая клетка
};


struct Game_System 			//Операторы системы
{
	std::string player_1;   	//Имя игрока 1
	std::string player_2;  	//Имя игрока 2
	bool party;				//
	int x;		    	 	//Координата x
	int y;		     	 	//Координата y
	tic_tac_toe_field field[3][3] = { {N,N,N},
									  {N,N,N},
									  {N,N,N} };	//Поле "крестики нолики"
	bool X_O;				// Метка крестик или нолик
	int Type_m;	  		//Ответ системе
	bool E_G;			//Конец партии
};

struct Game_Player 			//Операторы пользователя
{
	char Input;			// Ввод игрока
	bool for_whom[2];
};


void Difficulty_of_the_game()		//Функция настройки сложность игры
{
	std::cout << "Not implemented!\n\n";
}

void Computer()		//Функция игры с компьютером
{
	std::cout << "Not implemented!\n\n";
}

bool is_someone_won(tic_tac_toe_field field[3][3], int i, int j)
{
	if (field[i][j] == N)
	{
		return false;
	}
	if (i == 1 && j == 1)
	{
		if ((field[i][j] == field[i - 1][j - 1] && field[i][j] == field[i + 1][j + 1]))//диагональ слева сверху вправо снизу
		{
			return true;
		}
		if ((field[i][j] == field[i + 1][j - 1] && field[i][j] == field[i - 1][j + 1]))//диагональ справа сверху влево снизу
		{
			return true;
		}
	}
	if (j == 1 && (field[i][j] == field[i][j - 1] && field[i][j] == field[i][j + 1]))//горизонталь
	{
		return true;
	}
	if (i == 1 && (field[i][j] == field[i - 1][j] && field[i][j] == field[i + 1][j]))//вертикаль
	{
		return true;
	}
	return false;
}

void Rand_Party(bool& party)	//Функция выбора стороны
{
	srand(time(NULL));
	party = abs((rand() / 2) % 2);
}


void Stroke_function(int& x, int& y)// ввести ячейку
{
	bool r = 0;
	while (true)
	{
		std::cout << "Enter the field row first, then the column. All these actions are accompanied by the Enter key.\n";
		std::cin >> y;
		std::cin >> x;
		r = (x >= 1 && x <= 3 && y >= 1 && y <= 3) ? 0 : 1;
		if (r == 1)
		{
			std::cout << "Invalid values. Enter it again.\n";
		}
		else
		{
			break;
		}
	}
}

void Draw_a_field(tic_tac_toe_field(&field)[3][3]) //Рисовка поля
{
	std::cout << "\n#-#-#-#\n";
	for (int i = 1; i <= 3; i++)
	{
		std::cout << "|";
		for (int j = 1; j <= 3; j++)
		{
			switch (field[i - 1][j - 1])
			{
			case N:
				std::cout << " |";
				break;
			case X:
				std::cout << "X|";
				break;
			case O:
				std::cout << "O|";
				break;
			}
		}
		std::cout << "\n#-#-#-#\n";
	}
}

void End_or_continuation(bool& r, bool X_O, tic_tac_toe_field field[3][3], bool(&for_whom)[2], std::string p1, std::string p2)		//проверка на конец игры или продолжение
{
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (is_someone_won(field, i, j))
			{
				r++;
				std::cout << "The player " << ((for_whom[0] == X_O) ? p1 : p2) << " won.\n";
				std::cout << "The player " << ((for_whom[0] == X_O) ? p2 : p1) << " lose.\n";
			}
		}
	}
	if (r != 1)
	{
		std::cout << "The player " << ((for_whom[0] != X_O) ? p1 : p2) << " , make your move.\n";
	}

}



void Non_filling_conditions(bool(&for_whom)[2], std::string p1, std::string p2, bool& E_G)//Процесс игры.
{
	Game_System System;
	System.X_O = 1;
	bool r = 0;
	while (r == 0)
	{
		Stroke_function(System.x, System.y);
		if (System.field[System.y - 1][System.x - 1] != X && System.field[System.y - 1][System.x - 1] != O)
		{
			System.field[System.y - 1][System.x - 1] = (System.X_O == 1 ? X : O);
			Draw_a_field(System.field);
			End_or_continuation(r, System.X_O, System.field, for_whom, p1, p2);

			System.X_O = (System.X_O == 1) ? 0 : 1;
		}
		else
		{
			std::cout << "Occupied cell. Enter a new cell.";
		}
	}
	std::cout << "Enter Y if you want to continue playing, or N if you want to stop playing in this mode.";
	char p;
	std::cin >> p;
	E_G = (p == 'y') ? 0 : 1;
}

void Start_System_Game(char& message)   //Функции начала
{
	std::cout << "Welcome to the Tic-tac-toe game\n\n";
	std::cout << "1) Playing with a computer. \n";
	std::cout << "2) Two players. \n";
	std::cout << "3) Computer Difficulty Settings. \n";
	std::cout << "4) Exit the game.\n\n";
	while (true)
	{
		std::cout << "Enter the item number and press Enter\n\n";
		std::cin >> message;
		if (message == '1' || message == '2' || message == '3' || message == '4')
		{
			break;
		}
		else
		{
			std::cout << "Invalid response.\n";
		}
	}

}


void Players_Humans(void)			//Функция игры для игроков
{
	Game_System System;
	Game_Player Who;
	std::cout << "Enter the name of the first player and press Enter.\n";
	std::cin >> System.player_1;
	std::cout << "Enter the name of the second player and press Enter.\n";
	std::cin >> System.player_2;
	Rand_Party(System.party);
	if (System.party == 0)
	{
		std::cout << "Player " << System.player_1 << ", make your move.\n";
		std::cout << "Enter the coordinates of the cell.\n";
		Who.for_whom[0] = 1;   //игрок 1 играет за крестик
		Who.for_whom[1] = 0;   //игрок 2 играет за нолик
	}
	else
	{
		std::cout << "Player " << System.player_2 << ", make your move.\n";
		std::cout << "Enter the coordinates of the cell.\n";
		Who.for_whom[0] = 0; //игрок 1 играет за нолик
		Who.for_whom[1] = 1; //игрок 2 играет за крестик
	}
	while (System.E_G != 1)
	{

		Non_filling_conditions(Who.for_whom, System.player_1, System.player_2, System.E_G);
	}

}



void Choice(char& message, int& Type_m)    //Функция выбора действия
{
	Game_System System;
	switch (message)
	{
	case '1':
		Computer();
		break;
	case '2':
		Players_Humans();
		break;
	case '3':
		Difficulty_of_the_game();
		break;
	case '4':
		Type_m = 4;
	}
}



int main()
{
	Game_System System;
	Game_Player Player;
	while (System.Type_m != 4)
	{
		Start_System_Game(Player.Input);
		Choice(Player.Input, System.Type_m);
	}
	std::cout << "Exit from game! Thanks for game!\n\n";
	return 0;
}