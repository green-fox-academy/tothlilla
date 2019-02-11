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

 private:
  bool _isCaptain;
  bool _isWoodLeg;
  std::string _name;
  int _gold = 0;
  int _healthPoint = 10;


};

#endif //TRIALEXAM_PIRATES_PIRATE_H
