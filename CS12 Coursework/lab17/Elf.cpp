#include <iostream>
#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string FamilyName) : Character(ELF, name, health, attackStrength){
    this->FamilyName = FamilyName;
}
void Elf::attack(Character &opponent){
    if(opponent.getType() == ELF){
        Elf &opp = dynamic_cast<Elf &>(opponent);
        if(opp.FamilyName == FamilyName){
            cout << "Elf " << this->getName() << " does not attack Elf " << opponent.getName() << '.' << endl;
            cout << "They are both members of the " << this->FamilyName << " family." << endl;
            return;
        }
        cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << ((health / MAX_HEALTH) * attackStrength) << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - ((this->health / MAX_HEALTH) * attackStrength));
    }
    else{
        cout << "Elf " << this->getName() << " shoots an arrow at " << opponent.getName() << " --- TWANG!!" << endl;
        cout << opponent.getName() << " takes " << ((health / MAX_HEALTH) * attackStrength) << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - ((this->health / MAX_HEALTH) * attackStrength));
    }
}