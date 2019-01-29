#include <iostream>
#include <string>

//Create an Animal class
//  Every animal has a hunger value, which is a whole number
//  Every animal has a thirst value, which is a whole number
//  when creating a new animal object these values are created with the default 50 value
//Every animal can eat() which decreases their hunger by one
//  Every animal can drink() which decreases their thirst by one
//  Every animal can play() which increases both by one

class Animal
{
    public:
        Animal(int hunger, int thirst)
        {
            _hunger = 50;
            _thirst = 50;
        }


        void eat()
        {
            _hunger--;
        }


        void drink()
        {
            _thirst--;
        }

        void play()
        {
            _thirst++;
            _hunger++;
        }


    private:

        int _hunger;
        int _thirst;

};

int main(int argc, char* args[])
{


    return 0;
}