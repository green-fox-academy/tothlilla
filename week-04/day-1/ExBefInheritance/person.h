//
// Created by Lilla on 2019. 02. 03..
//
#ifndef EXBEFINHERITANCE_PERSON_H
#define EXBEFINHERITANCE_PERSON_H
#include <string>

//Case1
//const int MALE = 0; a const nem szükséges
//const int FEMALE = 1; a const nem szükséges
//const int TRANSGENDER= 2; a const nem szükséges
//public:
//Person (int gender)
//használat a main-ben:
//int GENDER FEMALE

//Ha enumot használok, akkor a main-ben ezt csinálom
//Scope resolution operator
//Person p(Gender::FEMALE);

enum Gender
{
    MALE,
    FEMALE
};
//a declarációnál kell a pontos vessző
std::string getGenderString(Gender gender); //ezt azért kell kivülre rakni, mert így fogja látni a student és a többiek
class Person
{
public:
  Person(std::string name, int age, Gender gender);
  Person();
  //std::string getGenderString(Gender gender);
  void introduce();
  void getGoal();
private:
    std::string _name;
    int _age;
    Gender _gender; // = Gender::FEMALE; //0: Male, 2: Female, 3: Transgender
};

#endif //EXBEFINHERITANCE_PERSON_H
