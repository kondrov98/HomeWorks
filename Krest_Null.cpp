#include <iostream>
#include <random>

enum class CellState {
    Empty, X, O
};

enum class Sign {
    X, O
};

struct GameField {
    CellState cells[9];
};

struct GameData {
    GameField field;
    Sign player_sign;
};

struct TurnOutcome {
    bool isOver : 1;
    Sign victor : 1;
    bool isDraw : 1;
};

struct Game_System 			//Операторы системы
	{
	 std::string player_1;   	//Имя игрока 1
	 std::string player_2;  	//Имя игрока 2
	 int x;		    	 	//Координата x
	 int y;		     	 	//Координата y
	 int Type_m;	  		//Ответ системе
	 bool party;
	 bool E_G;			//Конец партии
	}System;

struct Game_Player 			//Операторы пользователя
	{
	 Sign motion;      // Поле "крестики-нолики" со стороны игрока
	 char Input;			// Ввод игрока
	}Player;

void Rand_Party(bool& party)	//Функция выбора стороны
	{
	 party=rand()%2;
	}

void Start_System_Game(char& message)   //Функции начала
	{
	 std::cout<<"\nWelcome to the Tic-tac-toe game\n\n";
	 std::cout<<"1) Playing with a computer. \n";
	 std::cout<<"2) Two players. \n";
	 std::cout<<"3) Computer Difficulty Settings. \n";
	 std::cout<<"4) Exit the game.\n\n";
	 while(true)
		{
		 std::cout<<"Enter the item number and press Enter\n\n";
   		 std::cin>>message;
		 if(message == '1'||message == '2'||message == '3'||message == '4')
			{
			 break;
			}
		else
			{		 
			 std::cout<<"Invalid response.\n";
			}
		}
	   
	}



bool isValidCell(size_t row, size_t column) {
    return row >= 0 && row < 3 && column >= 0 && column < 3;
}

CellState getCell(const GameField& field, size_t row, size_t column) {
    if (!isValidCell(row, column)) return CellState::Empty;
    return field.cells[column * 3 + row];
}

bool isCellEmpty(const GameField& field, size_t row, size_t column) {
    return getCell(field, row, column) == CellState::Empty;
}

void putSign(GameField& field, Sign sign, size_t row, size_t column) {
    if (isValidCell(row, column)) {
        field.cells[column * 3 + row] = (sign == Sign::X) ? CellState::X : CellState::O;
    }
}

bool askQuestion(char positive, char negative) {
    char sign{};
    std::cin >> sign;
    sign = tolower(sign);

    while (sign != positive && sign != negative) {
        std::cout << "Wrong input: received '" << sign << "', should be one of " << positive << " or " << negative << "\n";
        std::cin >> sign;
        sign = tolower(sign);
    }
    return sign == positive;
}

Sign queryPlayerSign() {
    std::cout << "Please input wheter you're X or O: ";
    bool isX = askQuestion('x', 'o');
    return isX ? Sign::X : Sign::O;
}

TurnOutcome checkTurnOutcome(const GameField& field);

void processAiTurn(GameField& field, Sign ai_sign) {
    size_t empty_cells[9]{};
    const size_t kInvalidCellIdx = 42;
    std::fill_n(empty_cells, 9, kInvalidCellIdx);
    size_t last_empty_cell_idx = 0;
    for (size_t i = 0; i < 9; i++) {
        if (field.cells[i] == CellState::Empty) {
            empty_cells[last_empty_cell_idx] = i;
            last_empty_cell_idx++;
        }
    }

    static std::random_device rd;
    static std::mt19937 mt(rd());
    std::uniform_int_distribution<size_t> dist(0, last_empty_cell_idx - 1);

    for (size_t i = 0; i < last_empty_cell_idx; i++) {
        size_t target = empty_cells[i];
        field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
        auto outcome = checkTurnOutcome(field);
        if (outcome.isOver) {
            return;
        }
        field.cells[target] = CellState::Empty;

        auto opposite_sign = ai_sign == Sign::X ? Sign::O : Sign::X;
        field.cells[target] = opposite_sign == Sign::X ? CellState::X : CellState::O;
        outcome = checkTurnOutcome(field);
        if (outcome.isOver) {
            field.cells[target] = ai_sign == Sign::X ? CellState::X : CellState::O;
            return;
        }
        field.cells[target] = CellState::Empty;
    }
    size_t target = empty_cells[dist(mt)];
    putSign(field, ai_sign, target / 3, target % 3);
}

void processPlayerTurn(GameField& field, Sign player_sign) {
    std::cout << "\nEnter row and column: ";

    int row, column;
    std::cin >> row >> column;

    while (!isValidCell(row - 1, column - 1) || !isCellEmpty(field, row - 1, column - 1)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Wrong input, please enter row and column of an empty cell: ";
        std::cin >> row >> column;
    }

    putSign(field, player_sign, row - 1, column - 1);
}

void printField(const GameField& field);

bool isDraw(const GameField& field) {
    for (size_t i = 0; i < 9; i++) {
        if (field.cells[i] != CellState::Empty) {
            return false;
        }
    }
    return true;
}

bool checkLine(const GameField& field, size_t start_row, size_t start_column, int delta_row, int delta_column) {
    size_t current_row = start_row;
    size_t current_column = start_column;
    auto first = getCell(field, start_row, start_column);
    if (first == CellState::Empty) {
        return false;
    }
    while (isValidCell(current_row, current_column)) {
        if (getCell(field, current_row, current_column) != first) {
            return false;
        }
        current_row += delta_row;
        current_column += delta_column;
    }
    return true;
}

#define CHECK_LINE(start_row, start_column, delta_row, delta_column) \
        if (checkLine(field, start_row, start_column, delta_row, delta_column)) { \
            outcome.isOver = true; \
            outcome.victor = getCell(field, start_row, start_column) == CellState::X ? Sign::X : Sign::O; \
            return outcome; \
        }



TurnOutcome checkTurnOutcome(const GameField& field) {
    TurnOutcome outcome{};
    for (size_t row = 0; row < 3; row++) {
        CHECK_LINE(row, 0, 0, 1)
    }
    for (size_t column = 0; column < 3; column++) {
        CHECK_LINE(0, column, 1, 0)
    }
    CHECK_LINE(0, 0, 1, 1)
        CHECK_LINE(0, 2, 1, -1)

        if (isDraw(field)) {
            outcome.isDraw = true;
        }
    return outcome;
}

#undef CHECK_LINE

TurnOutcome runGameLoop(Sign player_sign) {
    GameData game_data{};
    TurnOutcome outcome{};

    while (true) {
        if (player_sign == Sign::X) {
            processPlayerTurn(game_data.field, Sign::X);
        }
        else {
            processAiTurn(game_data.field, Sign::X);
        }

        printField(game_data.field);
        outcome = checkTurnOutcome(game_data.field);
        if (outcome.isOver) {
            return outcome;
        }

        if (player_sign == Sign::O) {
            processPlayerTurn(game_data.field, Sign::O);
        }
        else {
            processAiTurn(game_data.field, Sign::O);
        }

        printField(game_data.field);
        outcome = checkTurnOutcome(game_data.field);
        if (outcome.isOver) {
            return outcome;
        }
    }
}

void printField(const GameField& field) {
    std::cout << "\n#-#-#-#\n";
    for (size_t row = 0; row < 3; row++) {
        std::cout << "|";
        for (size_t column = 0; column < 3; column++) {
            switch (getCell(field, row, column))
            {
            case CellState::Empty:
                std::cout << " |";
                break;
            case CellState::X:
                std::cout << "X|";
                break;
            case CellState::O:
                std::cout << "O|";
                break;
            }
        }
        std::cout << "\n";
	std::cout << "#-#-#-#\n";
    }
}

bool queryPlayAgain() {
    std::cout << "Want to play again? [y or n]: ";
    return askQuestion('y', 'n');
}

void printGameOutcome(const TurnOutcome& outcome, Sign player_sign) {
    if (outcome.isDraw) {
        std::cout << "It's a draw.\n";
    }
    else if (outcome.victor == player_sign) {
        std::cout << "Congrats! You're winner.\n";
    }
    else {
        std::cout << "No luck this time.\n";
    }
}

void Players_Humans(std::string& p1,std::string& p2)			//Функция игры для игроков
	{
	 std::cout<<"Enter the name of the first player and press Enter.\n";
	 std::cin>>p1;
	 std::cout<<"Enter the name of the second player and press Enter.\n";
	 std::cin>>p2; 
	 Rand_Party(System.party);
	 if(System.party==0)
	   	{
		 std::cout<<"Player "<<p1<<" make your move.\n";
		 std::cout<<"Enter the coordinates of the cell.\n";
		}
	else
		{
		 std::cout<<"Player "<<p2<<" make your move.\n";
		 std::cout<<"Enter the coordinates of the cell.\n";
		}
	while(System.E_G!=1)
		{
	         std::cout<<"\nNot ready yet!!!\n";
	 	 System.E_G=1;
		}
	 
	}

void Choice(char& message,int Type_m)    //Функция выбора действия
	{
	 if(message=='1')
		{
		 Sign player_sign = queryPlayerSign();
    		 bool shouldExit = false;
 	         while (!shouldExit) {
        		auto outcome = runGameLoop(player_sign);
        		printGameOutcome(outcome, player_sign);
       		 	shouldExit = !queryPlayAgain();
				     }
	         Start_System_Game(Player.Input);
		}
	else
		{
		 if(message=='2')
			{
			 Players_Humans(System.player_1,System.player_2);
			 Start_System_Game(Player.Input);
			}
		else
			{
			 if(message=='3')
				{
				 std::cout<<"\nNot implemented!!!\n";
				 Start_System_Game(Player.Input);
				}
			else
				{
				 System.Type_m=4;
				}
			}
		}
	}

int main() {
    Start_System_Game(Player.Input);
    while(System.Type_m!=4)
		{
		 Choice(Player.Input,System.Type_m);
		}
	 std::cout<<"Exit from game! Thanks for game!\n\n";
    
    return 0;
}