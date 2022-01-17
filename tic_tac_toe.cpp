#include <iostream>

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

int choice;
int row, colum;
char turn = 'X';
bool draw = false;

void display_board() {

    std::cout << "Player - 1 [X]\n Player - 2 [O]\n";
    std::cout << "  " << board[0][0] << "  |  " << board[0][1] << "   |  " << board[0][2] << "\n";
    //std::cout << " " << board[0][0] << "|" << board[0][1] << "|" << board[0][2] << "\n";
    std::cout << "_____|______|______\n";
    std::cout << "     |      |      \n";
    std::cout << "  " << board[1][0] << "  |" << board[1][1] << "     |   " << board[1][2] << " \n";
    std::cout << "_____|______|______\n";
    std::cout << "     |      |      \n";
    std::cout << "  " << board[2][0] << "  |" << board[2][1] << "     |   " << board[2][2] << " \n";
    std::cout << "     |      |      \n";

}


void player_turn() {
    if (turn == 'X') {
        std::cout << "\n Player - 1 [X] turn : ";
    }

    else if(turn == 'O') {

        std::cout << "\n Player - 2 [O] turn : ";
    
    }

    std::cin >> choice;

    switch (choice) {

    case 1: row = 0; colum = 0; break;
    case 2: row = 0; colum = 1; break;
    case 3: row = 0; colum = 2; break;
    case 4: row = 1; colum = 0; break;
    case 5: row = 1; colum = 1; break;
    case 6: row = 1; colum = 2; break;
    case 7: row = 2; colum = 0; break;
    case 8: row = 2; colum = 1; break;
    case 9: row = 2; colum = 2; break;

    default: std::cout << "invalid move";
    }

    if (turn == 'X' && board[row][colum] != 'X' && board[row][colum] != 'O') {

        board[row][colum] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][colum] != 'X' && board[row][colum] != 'O') {

        board[row][colum] = 'O';
        turn = 'X';
    }
    else {

        std::cout << "box is aldready filled in \n";
        player_turn();
    }

    display_board;
}

bool game_over() {

    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;

}

int main()
{
    std::cout << "TICK TAC TOE GAME \n";
    std::cout << "FOR 2 PLAYERS \n";

    while (game_over()) {

        display_board();
        player_turn();
        game_over();
    }

    if (turn == 'X' && draw == false) {

        std::cout << "Player with X wins";
    }
    else if (turn == 'O' && draw == false) {

        std::cout << "Player with O wins";
    }

    else {
        std::cout << " Game draw";
    }
}