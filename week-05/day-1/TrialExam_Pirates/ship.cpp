//
// Created by Lilla on 2019. 02. 11..
//

#include "ship.h"
Ship::Ship()
{

}
void Ship::addPirate(Pirate onepirate) {
  //_pirates.push_back(onepirate);
  if (!onepirate.captain()){
    _pirates.push_back(&onepirate);
  }
  if (onepirate.captain()){

  }

}
