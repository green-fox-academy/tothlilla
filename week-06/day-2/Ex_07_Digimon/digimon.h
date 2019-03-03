//
// Created by Lilla on 2019. 03. 03..
//

#ifndef EX_07_DIGIMON_DIGIMON_H
#define EX_07_DIGIMON_DIGIMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum digivolution
{
  BABY,
  IN_TRAINING,
  ROOKIE,
  CHAMPION,
  ULTIMATE,
  MEGA
};

typedef struct
{
  short age;
  short health;
  char name_digimon[127];
  char name_tamer[255];
  enum digivolution digi_level;
} digimon_t;

char * getlevel(enum digivolution digi_level);
int get_minimum_health_index(digimon_t * digimon_array, int size);
int count_digivolution_level(digimon_t * digimon_array, int size, enum digivolution digi_level);
int numb_same_tamer(digimon_t * digimon_array, int size, char name_tamer[]);


#endif //EX_07_DIGIMON_DIGIMON_H
