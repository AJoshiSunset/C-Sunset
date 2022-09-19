#include <iostream>

using namespace std;

/*
  Name: Avanish Joshi
  Date: 9-15-22
  Project: This is a guessing game. The computer 
  thinks of a number from 0-100, and asks the user
  will guess. The user keeps guessing until they
  get it right, and then the program will show 
  how many tries it took to get the number
 */

/*
  The 3 rules of c++:
  1. No global variables
  2. No strings
  3. Use <iostream>, not stdio
 */

int main()
{
  bool again = true;

  // the while loop that runs the whole program again
  // when the user wants to play again
  while (again == true) {

  // generates the random number
  int number = 0;
  srand(time(0));
  number = rand() % 100 + 0;

  // sets initial variables
  int tries = 0;
  bool won = false;

  // the while loop that keeps running as long as the
  // user does not guess the number
  while (won == false) {

    // allows the user to guess the number
    int guess = 0;
    cout << "Guess the number!" << endl;
    cin >> guess;
    
  if (guess > number) {
      // when the guess is too high
      cout << "Your guess is too high!" << endl;
      tries++;
      won = false;
    }
  else if (guess < number) {
      // when the guess is too low
      cout << "Your guess is too low!" << endl;
      tries++;
      won = false;
    }
  else {
    // when the guess is correct
    cout << "You got it right!" << endl;
    tries++;
    won = true;
  }

  }

  // prints out how many tries it took
  cout << "It took you " << tries << " tries!" << endl;

  // code for determining if the user wants to play again
  cout << "Do you want to play again? (1 for yes, any key for no)" << endl;
  int play = 1;
  cin >> play;

  // for when the user wants to play again
  if (play == 1) {
      cout << "Playing again!" << endl;
      again = true;
    }
  else {
    // for when the user doesn't want to play again
    cout << "Goodbye" << endl;
    again = false;
  }
  
  }
  
  return 0;
}
