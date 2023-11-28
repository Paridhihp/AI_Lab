#include "iostream"
#include "vector"
#include "math.h"
#include "stdio.h"
#include "string.h"
using namespace std;

char board[3][3];               // each cell is ' ', 'X' or 'O'

void display_table(){
    cout << "+-+-+-+\n";
    for (int i = 0; i < 3; ++i){
        for (int j = 0; j < 3; ++j){
            cout << '|' << board[i][j];
        }
        cout << "|\n";
    }
    cout << "+-+-+-+\n";
}


// Given a vector of previous moves by a player and the current move,
// all represented  as the values in a 3x3 magic square, return true
// if the player has a winning combination
bool check_winner(const vector<int> &prevMoves, int curMove){
    for (unsigned i=0; i+1< prevMoves.size(); ++i) {
	for (unsigned j=i+1; j<prevMoves.size(); ++j) {
	    if (prevMoves[i]+prevMoves[j]+curMove == 15) {
		return true;
	    }
	}
    }
    return false;
}

int main()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';

    cout << "\nTic Tac toe\n\n";
    display_table();
    cout << '\n';
    bool tie = true;
    int x, y;
    int magicSquare[9] = {8,1,6,3,5,7,4,9,2};
    vector<int> magicMoves[2];	  // Players' moves so far, as numbers in magic square
    for (int i = 0; i < 9; ++i) { // even for X, odd for O
	int playerNum = i%2;
        char mark = (playerNum ? 'O' : 'X');
        cout<<"Coordinates can only be an int in [1,3]!\n";
        cout << mark << " its your turn, enter co-ordinates : ";

        while (true) {
            cin >> x >> y;
            --x; --y;           // immediately convert 1-3 into 0-2

            if(x > 2 || y > 2 || x < 0 || y < 0) {
                cout << "Coordinates can only be an int in [1,3]!\nEnter correc\
t value : ";
            } else if (board[x][y] != ' ') {
                cout << "Filled box! Enter different values : ";
            } else {
                break;          // the values are good.
            }
        }

        board[x][y] = mark;
        display_table(); // display the table
	int square = magicSquare[3*x+y];
        if(check_winner(magicMoves[playerNum], square)) {
            cout << "We have a winner!\n";
            cout << mark << " is the winner!\n";
            tie = false;
            break;
        }
	magicMoves[playerNum].push_back(square);
    }
    if( tie)cout << "Tie!\n";
    return 0;
}