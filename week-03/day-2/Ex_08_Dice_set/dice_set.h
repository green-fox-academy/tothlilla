//
// Created by Lilla on 2019. 01. 30..
//

#ifndef EX_08_DICE_SET_DICE_SET_H
#define EX_08_DICE_SET_DICE_SET_H

#include <iostream>
#include <vector>

class DiceSet
{
public:

    DiceSet();

    void roll();
    void roll(int i);
    std::vector<int> getCurrent() const;
    int getCurrent(int i) const;
private:
    std::vector<int> dices;
};

#endif //EX_08_DICE_SET_DICE_SET_H
