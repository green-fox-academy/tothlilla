//
// Created by Lilla on 2019. 02. 06..
//

#include "animal.h"
std::string genderToString(Gender gender)
{
  if (gender == Gender::MALE) {
    return "male";
  } else if (gender == Gender::FEMALE) {
    return  "female";
  }
}