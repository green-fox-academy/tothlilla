/*Write a program which can store pirates in a ship.

Pirate:

- A pirate has a name, an amount of gold and health points, the default value of which is 10.
- A pirate might be a captain and may have a wooden leg.
- You must create the following methods:

- if a pirate is a captain:
- `work()` which increases the amount of gold possessed by that pirate by 10 and decrease the HP by 5.
- `party()` which increases the HP by 10.
- if the pirate is not a captain:
- `work()` which increases the amount of gold by 1 and decreases the HP by 1.
- `party()` which increases the HP by 1.

- if the pirate has a wooden leg, then the string that is returned by the function must look like this:
- Hello, I'm Jack. I have a wooden leg and 20 golds.
-  If not:
- Hello, I'm Jack. I still have my real legs and 20 golds.

Ship:

- It should have a list of pirates.
- You must be able to add new pirates to the ship. It must have only one captain!
- You must create the following methods:
- `getPoorPirates()` which returns a list of names containing the pirates that
- have a wooden leg and have less than 15 golds
- `getGolds()` which returns the sum of gold owned by the pirates of that particular ship
- `lastDayOnTheShip()` which calls the pirates' `party()` method.
- `prepareForBattle()` which calls
- the pirates' `work()` method 5 times
- then the ship's `lastDayOnTheShip()` method.
 */

#include <iostream>
#include "pirate.h"
#include "ship.h"

int main()
{
  Pirate pirate1("Jack Sparrow", true, false);
  Pirate pirate2("Captain Hook", true, true);
  Pirate pirate3("Blackburn 'Weasel' Lore", false, true);

  std::cout << pirate1.toString() << std::endl;
  std::cout << pirate2.toString() << std::endl;
  std::cout << pirate3.toString() << std::endl;

  Ship ship;
  ship.addPirate(pirate1);
  ship.addPirate(pirate2);
  ship.addPirate(pirate3);

  ship.prepareForBattle();
  ship.lastDayOnTheShip();


  std::cout << "The names of the poor pirates are: " << std::endl;
  std::vector<std::string> poorPirateNames = ship.getPoorPirates();
  for (int i = 0; i < poorPirateNames.size(); ++i) {
    std::cout << "\t" << poorPirateNames[i] << std::endl;
  }

  std::cout << "The total amount of gold on the ship is " <<ship.getGolds() << std::endl;

  return 0;
}