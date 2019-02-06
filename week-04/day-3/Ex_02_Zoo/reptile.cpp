//
// Created by Lilla on 2019. 02. 06..
//

#include "reptile.h"
Reptile::Reptile(std::string name)
{
  _name = name;
  //breed();

}
std::string Reptile::getName()
{
  return _name;
}