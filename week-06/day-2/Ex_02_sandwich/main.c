#include <stdio.h>
#include <string.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/
struct sandwich {
  unsigned char name[20];
  float price;
  float weight;
};

float price(struct sandwich sandwich, int order);

int main()
{
  struct sandwich big_sandwich;
  strcpy(big_sandwich.name, "Big Sandwich");
  big_sandwich.price = 5.50;
  big_sandwich.weight = 500;
  int newOrder;
  printf("How many %s do you want?\n", big_sandwich.name);
  scanf("%d", &newOrder);
  printf("The final price is %.2f \n", price(big_sandwich, newOrder));

  return 0;
}

float price(struct sandwich sandwich, int order)
{
  float finalPrice = (sandwich.price * order);

  return finalPrice;
}