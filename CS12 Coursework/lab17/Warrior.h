#ifndef __WARRIOR_H__
#define __WARRIOR_H__
#include <iostream>
#include "Character.h"

using namespace std;


class Warrior : public Character{
 private:
        string Allegiance;

 public:
     Warrior(const string &name, double health, double attackStrength, string Allegiance);
     void attack(Character &opponent);
 };
#endif