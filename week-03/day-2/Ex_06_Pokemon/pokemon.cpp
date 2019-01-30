//
// Created by Lilla on 2019. 01. 30..
//
//Every pokemon has a name and a type. Certain types are effective against others, e.g. water is effective against fire.
//You have a Pokemon class with a method called isEffectiveAgainst().
//Ash has a few pokemon. Help Ash decide which Pokemon to use against the wild one.
//You can use the already created pokemon files.

#include "pokemon.h"
#include <iostream>

Pokemon::Pokemon(const std::string& name, const std::string& type, const std::string& effectiveAgainst)
{
    _name = name;
    _type = type;
    _effectiveAgainst = effectiveAgainst;
}

bool Pokemon::isEffectiveAgainst(Pokemon anotherPokemon)
{
    return _effectiveAgainst == anotherPokemon._type;
}
