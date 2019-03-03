//
// Created by Lilla on 2019. 03. 03..
//
#include "digimon.h"

char * getlevel(enum digivolution digi_level)
{
	char level_name[20];
	if (digi_level == BABY) {
		return "baby";
	} else if (digi_level == ROOKIE) {
		return "rookie";
	} else if (digi_level == IN_TRAINING) {
		return "in-trainig";
	} else if (digi_level == CHAMPION) {
		return "champion";
	} else if (digi_level == ULTIMATE) {
		return "ultimate";
	} else if (digi_level == MEGA) {
		return "mega";
	} else {
		return "invalid value";
	}
}
int get_minimum_health_index(digimon_t * digimon_array, int size)
{
	int index_min_health = 0;
	for (int i = 0; i < size; ++i) {
		if (digimon_array[i].health < digimon_array[index_min_health].health) {
			index_min_health = i;
		}
	}
	return index_min_health;
}
int count_digivolution_level(digimon_t * digimon_array, int size, enum digivolution digi_level)
{
	int counter = 0;

	for (int i = 0; i < size; ++i) {
		if (digimon_array[i].digi_level == digi_level)
			counter++;
	}
	return counter;
}

int numb_same_tamer(digimon_t * digimon_array, int size, char name_tamer[])
{
	int same_tamer_counter = 0;

	for (int i = 0; i < size; ++i) {
		if (strcmp (digimon_array[i].name_tamer, name_tamer) == 0)
			same_tamer_counter++;
	}
	return same_tamer_counter;
}
