//
// Created by Lilla on 2019. 02. 11..
//

#ifndef TRIALEXAM_PIRATES_PIRATE_H
#define TRIALEXAM_PIRATES_PIRATE_H
#include <iostream>
class Pirate {
 public:
  Pirate(std::string name, bool isCaptain, bool isWoodLeg);
  void work();
  void party();
  bool captain();
  bool woodLeg();
  std::string toString();
  int getGold();
  int _gold;
  std::string _name;
  std::string getName();

 private:
  bool _isCaptain;
  bool _isWoodLeg;


  int _healthPoint;


};

#endif //TRIALEXAM_PIRATES_PIRATE_H
