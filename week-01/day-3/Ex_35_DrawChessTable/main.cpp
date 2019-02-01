#include <iostream>

int main(int argc, char* args[])
{
    // Crate a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    int chessRow = 8;
    for (int i = 0; i < chessRow; ++i) {
        for (int j = 0; j < chessRow; ++j) {
            if (i % 2 == 1) {         //the case of odd rows
                while (j < chessRow / 2) {
                    std::cout << " %";
                    ++j;
                }
            } else {
                while (j < chessRow / 2) { // //the case of even rows
                    std::cout << "% ";
                    ++j;
                }
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
