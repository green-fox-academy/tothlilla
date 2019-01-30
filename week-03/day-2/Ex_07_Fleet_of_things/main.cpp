#include <iostream>
#include "fleet.h"
#include "thing.h"

//You have the Thing class
//You have the Fleet class
// Download those, use those
// In the main function create a fleet
// Achieve this output:
//1. [ ] Get milk
//2. [ ] Remove the obstacles
//3. [x] Stand up
//4. [x] Eat lunch

int main(int argc, char* args[])
{

    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch
    Fleet fleet;


    Thing first("Get milk"); //first is the First object
    fleet.add(first); //we add the first object to the result, and changed the value of result


    Thing second("Remove the obstacles"); //second is the Second object
    fleet.add(second); //we add the second object to the result, and changed the value of result


    Thing third("Stand up"); //third is the Third object
    third.complete(); //we manipulate the third object with a bool
    fleet.add(third); //we add the third object to the result, and changed the value of result



    Thing fourth("Eat lunch"); //fourth is the Fourth object
    third.complete(); //we manipulate the fourth object with a bool
    fleet.add(third); //we add the fourth object to the result, and changed the value of result


    std::cout << fleet.toString() << std::endl;
    return 0;
}