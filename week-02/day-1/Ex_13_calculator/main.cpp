#include <iostream>
#include <vector>

std::vector<...> calulator(operation, operand);

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
  std::cout << "Please type in the expression:" << std::endl;
  std::vector<std::string> calcOne[0];
  int sizeOneVector = sizeof(calcOne) / sizeof(calcOne[0]);
  std::string operation = "";
  std::vector<int> operand(1);
  int sizeTwoVector = sizeof(operand) / sizeof(operand[0]);
  std::cin >> operation[0] >> operand[0] >> operand[1];
  calulator(operation, operand);



  return 0;
}