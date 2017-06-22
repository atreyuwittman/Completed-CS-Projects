#include <iostream>
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, const int rank) : Character(WIZARD, name, health, attackStrength){
    this->rank = rank;
}

void Wizard::attack(Character &opponent){
    if(opponent.getType() == WIZARD){
        Wizard &opp = dynamic_cast<Wizard &>(opponent);
        double damage = (static_cast<double>(rank) / static_cast<double>(opp.rank));
        cout << "Wizard " << this->getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << (attackStrength * damage) << " damage." << endl;
        opp.setHealth(opponent.getHealth() - (attackStrength * damage));
    }
    else{
        cout << "Wizard " << this->getName() << " attacks " << opponent.getName() << " --- POOF!!" << endl;
        cout << opponent.getName() << " takes " << (attackStrength) << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - attackStrength);
    }
}
