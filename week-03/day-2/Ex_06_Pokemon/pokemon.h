//
// Created by Lilla on 2019. 01. 30..
//
//Every pokemon has a name and a type. Certain types are effective against others, e.g. water is effective against fire.
//You have a Pokemon class with a method called isEffectiveAgainst().
//Ash has a few pokemon. Help Ash decide which Pokemon to use against the wild one.
//You can use the already created pokemon files.

#ifndef EX_06_POKEMON_POKEMON_H
#define EX_06_POKEMON_POKEMON_H

#include <iostream>

class Pokemon {
public:
    Pokemon(const std::string& name, const std::string& type, const std::string& effectiveAgainst);

    bool isEffectiveAgainst(Pokemon anotherPokemon);

    std::string _name;
    std::string _type;
    std::string _effectiveAgainst;
};


#endif //EX_06_POKEMON_POKEMON_H
