#include "digimon.h"
/* Digimon database!
 * You should store the following data in a structure
 *  - the name of the digimon (which is shorter than 128 characters)
 *  - the age of the digimon (in years)
 *  - the health of the digimon (between 0-100)
 *  - the name of the tamer (which is shorter than 256 characters)
 *  - the digivolution level of the digimon (as a custom type, see below)
 */
/* You should store the digivolution level in an enumeration
 * the valid digivolution levels are:
 *  - baby
 *  - in-training
 *  - rookie
 *  - champion
 *  - ultimate
 *  - mega
 *
 * The digimons are stored in an array.
 *
 * Write the following functions:
 * Done 1) Get minimum health index
 *      - parameters:
 *          - array
 *          - array length
 *      - it returns the index of the minimal health digimon in the "array"
 * Done 2) Get same digivolution level count
 *      - parameters:
 *          - array
 *          - array length
 *          - digivolution level
 *      - it returns the count of digimons which are at "digivolution level"
 * Done 3) Get same tamer count
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the count of the digimons which have the same tamer as "tamer name"
 * 4) Get average health of the same tamer
 *      - parameters:
 *          - array
 *          - array length
 *          - tamer name
 *      - it returns the average health of the digimons which have the same tamer as "tamer name"
 *
 * Don't forget to handle invalid inputs (NULL pointers, invalid values etc.)
 */

int main()
{
	int size = 5;
	digimon_t digimon_array[size];
	digimon_array[0].age = 1;
	digimon_array[0].health = 65;
	digimon_array[0].digi_level = BABY;
	strcpy(digimon_array[0].name_tamer,"Apa");

	digimon_array[1].age = 2;
	digimon_array[1].health = 53;
	digimon_array[1].digi_level = ROOKIE;
	strcpy(digimon_array[1].name_tamer,"Apa");


	digimon_array[2].age = 4;
	digimon_array[2].health = 72;
	digimon_array[2].digi_level = CHAMPION;
	strcpy(digimon_array[2].name_tamer,"Anya");


	digimon_array[3].age = 6;
	digimon_array[3].health = 85;
	digimon_array[3].digi_level = ULTIMATE;
	strcpy(digimon_array[3].name_tamer,"Gyerekek");


	digimon_array[4].age = 4;
	digimon_array[4].health = 62;
	digimon_array[4].digi_level = CHAMPION;
	strcpy(digimon_array[4].name_tamer,"Anya");


	printf("The index of minimum health among the digimon is %d\n", get_minimum_health_index(digimon_array, size));
	printf("The number of %s level digimon is %d\n", getlevel(CHAMPION), count_digivolution_level(digimon_array, size, CHAMPION));
	printf("The number of %s's digimons is %d\n", "Gyerekek", numb_same_tamer(digimon_array, size, "Gyerekek"));
    return 0;
}