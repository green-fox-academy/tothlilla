//
// Created by Lilla on 2019. 02. 11..
//

#ifndef TRIALEXAM_PIRATES_SHIP_H
#define TRIALEXAM_PIRATES_SHIP_H
#include <vector>
#include "pirate.h"

class Ship {
 public:
  Ship();

  std::vector<std::string> getPoorPirates();
  int getGolds();
  void lastDayOnTheShip();
  void prepareForBattle();
  void addPirate(Pirate onepirate);

 private:
  //std::vector<Pirate> _pirates;
  std::vector<Pirate> _pirates;

};

#endif //TRIALEXAM_PIRATES_SHIP_H
