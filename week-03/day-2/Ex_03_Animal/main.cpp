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
        void eat()
        {
            _hunger--;
            std::cout << "The hungry: " <<_hunger << std::endl;
        }
        void drink()
        {
            _thirst--;
            std::cout << "The thirst: " << _thirst << std::endl;
        }
        void play()
        {
            //_thirst++;
            //_hunger++;
            //std::cout << "The hungry and the thirst: " << _hunger << " and " << _thirst << std::endl;
            eat();
            drink();
        }
    private:

        int _hunger = 50;
        int _thirst = 50;
};

int main(int argc, char* args[])
{
    Animal tiger;
    tiger.eat();
    std::cout << "\n";
    Animal lion;
    lion.play();
    lion.drink();

    return 0;
}