#include <iostream>
#include <ctype.h>
#include <cctype>
#include <cstring>

using namespace std;

/*
  Name: Avanish Joshi
  Date: 9-23-22
  Project: This project sees if your input
  is a palindrome or not. It ignores all
  punctuation, numbers, and spaces. The max
  character limit is 80.
 */

int main()
{
  // creates the variable for the input
  char input[81];

  // reads it in from the user
  cin.get(input, 81);
  cin.get();

  int inputlen = strlen(input);

  // gets rid of non-letter characters
  // and readjusts the string accordingly
  for (int a = 0; a < inputlen; a++) {

    // if a non-letter is detected
    if (!isalpha(input[a])) {
      int count = a;

      // shifts the string backwards
      while (count != inputlen) {
	input[count] = input[count + 1];
	count++;
      }
      
      inputlen--;
      a--;
    }
    // makes the string uppercase
    input[a] = toupper(input[a]);
  }

  //checks for if the input is a palindrome
  // by comparing the first and last halves
  // of the string
  for (int i = 0; i < inputlen / 2; i++) {

    if (input[i] != input[inputlen - i - 1]) {

      cout << "Nope! This is not a palindrome";
      return 0;
    }
  }
  
  cout << "Yup! This is a palindrome";
  
  return 0;
}
