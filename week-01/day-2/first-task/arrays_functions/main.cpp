/* #include <iostream>
#include <string>

void greet();

int main(int argc, char* args[]) {

    greet();

    return 0;
}

void greet() {
    std::cout << "Hello Green Fox!" << std::endl;
}
*/

/* #include <iostream>
#include <string>

void sayGreen();
void sayFox();

int main(int argc, char* args[]) {
    sayGreen();
    std::cout << "Hello from main()" << std::endl;
    return 0;
}

void sayGreen() {
    std::cout << "Green ";
    sayFox();
    std::cout << "Hello from sayGreen()" << std::endl;
}

void sayFox() {
    std::cout << "Fox" << std::endl;
    std::cout << "Hello from sayFox()" << std::endl;
}
 */

#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    int myNumbers[] = {1, 2, 3, 6};

    // Print the second element of the array
    std::cout << "The second element is: " << myNumbers[1] << std::endl;

    // Print all the elements
    for(int i = 0; i < sizeof(myNumbers)/sizeof(myNumbers[0]); i++) {
        std::cout << myNumbers[i] << std::endl;
    }

    return 0;
}