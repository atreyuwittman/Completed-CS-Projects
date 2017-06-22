#ifndef __ELF_H__
#define __ELF_H__
#include <iostream>
#include "Character.h"

using namespace std;

class Elf : public Character{
    private:
    string FamilyName;
 public:
     Elf(const string &name, double health, double attackStrength, string FamilyName);
     void attack(Character &opponent);
 };
#endif