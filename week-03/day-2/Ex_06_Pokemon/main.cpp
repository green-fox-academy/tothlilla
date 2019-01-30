#include <iostream>
#include <vector>
#include "pokemon.h"
#include <string>

//Every pokemon has a name and a type. Certain types are effective against others, e.g. water is effective against fire.
//You have a Pokemon class with a method called isEffectiveAgainst().
//Ash has a few pokemon. Help Ash decide which Pokemon to use against the wild one.
//You can use the already created pokemon files.

std::vector<Pokemon> initializePokemons()
{
    std::vector<Pokemon> pokemons;

    pokemons.push_back(Pokemon("Balbasaur", "leaf", "water"));
    pokemons.push_back(Pokemon("Pikatchu", "electric", "water"));
    pokemons.push_back(Pokemon("Charizard", "fire", "leaf"));
    pokemons.push_back(Pokemon("Balbasaur", "water", "fire"));
    pokemons.push_back(Pokemon("Kingler", "water", "fire"));

    return pokemons;
}

int main(int argc, char* args[])
{
    std::vector<Pokemon> pokemonOfAsh = initializePokemons();

    // Every pokemon has a name and a type.
    // Certain types are effective against others, e.g. water is effective against fire.

    // Ash has a few pokemon.
    // A wild pokemon appeared!

    Pokemon wildPokemon("Oddish", "leaf", "water"); //This is an object
    std::string name;

    for (int i = 0; i < pokemonOfAsh.size(); ++i) { //The number of loops is equal with the size
        if (pokemonOfAsh[i].isEffectiveAgainst(wildPokemon)){ // one of Ash's pokemon tested by the bool, and we compare against wildpokemon's value
            name = pokemonOfAsh[i]._name;
        }
    }



    // Which pokemon should Ash use?


    std::cout << "I choose You, " << name << std::endl;
    return 0;
}