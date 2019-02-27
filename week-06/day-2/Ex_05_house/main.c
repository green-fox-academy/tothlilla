#include <stdio.h>
#include <string.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/
struct house{
    char address[200];
    double price_EUR;
    int number_of_rooms;
    double area_of_house;
};
void it_is_worth(struct house *one_house);
int count_houses_to_worth(struct house array[], int size);
int main()
{
    struct house big_house;
    strcpy(big_house.address, "Heaven Street 7.");
    big_house.price_EUR = 55600;
    big_house.number_of_rooms = 2;
    big_house.area_of_house = 70;
    it_is_worth(&big_house);
    struct house small_house;
    strcpy(small_house.address, "Devil Street 6.");
    small_house.price_EUR = 10333;
    small_house.number_of_rooms = 1;
    small_house.area_of_house = 40;
    it_is_worth(&small_house);
    struct house very_big_house;
    strcpy(very_big_house.address, "Devil Street 6.");
    very_big_house.price_EUR = 61035;
    very_big_house.number_of_rooms = 4;
    very_big_house.area_of_house = 156.5;
    it_is_worth(&very_big_house);
    struct house array[] = {big_house, small_house, very_big_house};

    int sizeOfArray = sizeof(array) / sizeof(array[0]);
    printf("%d\n", sizeOfArray);
    printf("The number of houses are worth to buy is %d.", count_houses_to_worth(array,sizeOfArray));

    return 0;
}
void it_is_worth(struct house *one_house)
{
    if (one_house->price_EUR/one_house->area_of_house < 400){
        printf("The house with %d rooms and %.2lf EUR price is worth to buy.\n", one_house->number_of_rooms, one_house->price_EUR);
    } else {
        printf("This house with %d rooms and %.2lf EUR price is not worth to buy.\n", one_house->number_of_rooms, one_house->price_EUR);
    }
}
int count_houses_to_worth(struct house array[], int size)
{
    int counter = 0;
    for (int i = 0; i < size ; ++i) {
        if (array[i].price_EUR/array[i].area_of_house < 400){
            counter++;
        }
    }
  return counter;
}