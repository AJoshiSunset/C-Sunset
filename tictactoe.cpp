using namespace std;

#include <iostream>
#include <cstring>
#include <ctype.h>

/*
  Name: Avanish Joshi
  Date: 10-11-22
  Project: This is a recreation of tictactoe in C++. This is a two player
  game with no AI. X always starts first, and at the end of every game
  (after a win or tie) it shows how many times X and O has won.

 */

// creates the struct for variables that store the current turn and wins
struct players {
  char turn = 'X';
  int xwins = 0;
  int owins = 0;
};

// this function checks for a win condition after every turn
bool checkForWin(char board[3][3], char turn) {

  // checks the horizontal and vertical components
  for (int a = 0; a < 3; a++) {
    if (board[a][0] == turn && board[a][1] == turn && board[a][2] == turn) {
      return true;
    }
    if (board[0][a] == turn && board[1][a] == turn && board[2][a] == turn) {
      return true;
    }
  }
  // checks the diagnol components
  if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) {
    return true;
  }
  if (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn) {
    return true;
  }
  return false;
}

// this function checks for a tie. Checks if every space on the board
// is an 'X' or 'O'
bool checkForTie(char board[3][3]) {
  for (int a = 0; a < 3; a++) {
    for (int b = 0; b < 3; b++) {
      if (!(board[a][b] == 'X' || board[a][b] == 'O')) {
	return false;
      }
    }
  }
  return true;
}

// main function that runs the game 
int main() {

  // sets up some variables
  int input = 0;
  players tictactoe;

  // outer while loop that for determining if the player wants to play again
  while (1 == 1)
    {
      char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
      input = 0;
      tictactoe.turn = 'X';

  // inner while loop that has the main game code
  while (1 == 1)
    {

      // sets the board
      cout << "  |  "<< board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  |" << endl;
      cout << "  |-----|-----|-----|" << endl;
      cout << "  |  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  |" << endl;
      cout << "  |-----|-----|-----|" << endl;
      cout << "  |  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  |" << endl;

     
  cout << tictactoe.turn << "'s turn!" << endl;
  cout << "Input: " << endl;
  cin >> input;

  // if the input is not a number
  if (!cin)
    {
      cout << "Invalid input!" << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }

  // if the input is not between 1 and 9
  if (input > 9 || input < 1)
    {
      cout << "Invalid input!" << endl;
      continue;
    }

  // if the space already taken up by an 'X' or 'O'
  if (board[((input - 1)-(input % 3 - 1))/3][input % 3 - 1] == 'X' || board[((input - 1)-(input % 3 - 1))/3][input % 3 - 1] == 'O') {
    cout << "Ivalid input!" << endl;
    continue;
  }

  // changes the proper board space to an 'X' or 'O' by converting to base 3
  board[((input - 1)-(input % 3 - 1))/3][input % 3 - 1] = tictactoe.turn;

  // if there is a winning condition
  if (checkForWin(board, tictactoe.turn) == true) {
    cout << tictactoe.turn << " Wins!" << endl;
    if (tictactoe.turn == 'X') {
      tictactoe.xwins++;
    }
    else {
      tictactoe.owins++;
    }
    break;
  }

  // if there is a tie condition
  if (checkForTie(board) == true) {
    cout << "Tie!" << endl;
    break;
  }

  // if no wins, switch turns and continue
  if (tictactoe.turn == 'X')
    {
      tictactoe.turn = 'O';
    }
  else
    {
      tictactoe.turn = 'X';
    }
  
    }

  // after a win or tie: print the wins
  cout << "X wins: " << tictactoe.xwins << endl;
  cout << "O wins: " << tictactoe.owins << endl;

  // code to determine if user wants to play again
  char play;
  cout << "Do you want to play again? (y for yes, any key for no)" << endl;
  cin >> play;

  if (play == 'y') {
    continue;
  }
  else {
    break;
  }

    }
  cout << "Thanks for playing!" << endl;
  
  return 0;
}
