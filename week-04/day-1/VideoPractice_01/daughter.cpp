//
// Created by Lilla on 2019. 02. 05..
//
#include <iostream>
#include "mother.h"
#include "daughter.h"

Daughter::Daughter()
{

}
void Daughter::doSomething()
{
    publicv = 1;
    protectedv = 2;
    //privatev = 3; this case is not allowed, because this is only of base class!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}