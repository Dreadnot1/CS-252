/* CS 252 | Prof Dietrich | Lab 3
   Note: this Lab's Python code is at
   https://replit.com/@deets/lab-3-helper-python Please fork the repl so you
   have it in your account */
#include <iostream>
using namespace std;

int main() {
  // declarations
  int start;
  int iter;
  int step;
  int current = 0;

  /* PART ONE: Convert this Python code to C++:

  # obtain starting number
  start = int(input('Enter a starting number: '))
  # obtain number of iterations
  iter = int(input('Enter the number of iterations: '))
  # obtain the step value
  step = int(input('Enter a step value: '))
  # output the basic table
  current = 0
  for i in range(iter):
      current = start * i + step
      print(f'Iteration #{i+1}: {current}')
  */

  // code here for PART ONE
  cout << "Enter a starting number: ";
  cin >> start;

  cout << "Enter the number of iterations: ";
  cin >> iter;

  cout << "Enter a step value: ";
  cin >> step;

  for (int i = 0; i < iter; i++) {
    current = start * i + step;
    cout << "Iteration #" << i+1 << ":" << current << endl;
  }

  /* PART TWO: Convert this Python code to C++:
  for c in range(0,110,10):
      fah = c * 1.8 + 32
      print(f'{c} degrees Celcius is {fah} Fahrenheit')
  */

  // code here for PART TWO

  /* PART THREE: Convert this Python code to C++:
  sum = 0
  entry = 1  # dummy to start loop
  while entry != 0:
      entry = int(input('Enter an integer to sum, 0 to quit: '))
      sum += entry
  print(f'The sum is {sum}.')
  */

  // code here for PART THREE

  return 0;
}