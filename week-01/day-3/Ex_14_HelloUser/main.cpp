/* #include <iostream>
#include <string>

int main(int argc, char* args[]) {
    
    int numberOfWindows;
    std::cout << "Please enter how many windows do you see (integer): ";
    std::cin >> numberOfWindows;

    std::string colorOfCurtain;
    std::cout << "Please enter the color of the curtain (string): ";
    std::cin >> colorOfCurtain;

    std::cout << "You can see " << numberOfWindows << " windows from your place with beautiful " << colorOfCurtain << " curtain." << std::endl;

    return 0;
}
 */

#include <iostream>

int main(int argc, char* args[]) {

    // Modify this program to greet user instead of the World!
    // The program should ask for the name of the user
    std::string userName;
    std::cout << "Please enter your name :";
    std::cin >> userName;
    std::cout << "Hello " << userName << std::endl;

    return 0;
}