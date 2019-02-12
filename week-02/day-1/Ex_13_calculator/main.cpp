#include <iostream>
#include <vector>


void calulator(char operation, int operand1, int operand2);

int main(int argc, char* args[])
{
  // Create a simple calculator application which reads the parameters from the prompt
  // and prints the result to the prompt.

  // It should support the following operations: +, -, *, /, % and it should support two operands.
  // The format of the expressions must be: {operation} {operand} {operand}.
  // Examples:
  // "+ 3 3" (3 + 3 -> the result will be 6)
  // "* 4 4" (4 * 4 -> the result will be 16)
  // "/ 20 8" (20 / 8 -> the result will be 2)
  // "% 20 8" (20 % 8 -> the result will be 4)

  // It should work like this:
  // Start the program
  // It prints: "Please type in the expression:"
  // Waits for the user input
  // Print the result to the prompt
  // Exit
  std::cout << "Please type in the expression {operation} {operand} {operand}:" << std::endl;
  char operation;
  int operand1, operand2;
  std::cin >> operation >> operand1 >> operand2;

  calulator(operation, operand1, operand2);

  return 0;
}
void calulator(char operation, int operand1, int operand2)
{
  switch(operation){
    case '+':
      std::cout << operand1 + operand2;
      break;
    case '-':
      std::cout << operand1 - operand2;
      break;
    case '*':
      std::cout << operand1 * operand2;
      break;
    case '/':
      std::cout << operand1 / operand2;
      break;
    case '%':
      std::cout << operand1 % operand2;
      break;
    default:
      std::cout << "Invalid expressions";

  }
}