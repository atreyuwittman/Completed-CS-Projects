#include <iostream>
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, string Allegiance) : Character(WARRIOR, name, health, attackStrength){
    this->Allegiance = Allegiance;
}
void Warrior::attack(Character &opponent){
    if(opponent.getType() == WARRIOR){
        Warrior &opp = dynamic_cast<Warrior &>(opponent);
        if(opp.Allegiance == Allegiance){
            cout << "Warrior " << this->getName() << " does not attack Warrior " << opponent.getName() << '.' << endl;
            cout << "They share an allegiance with " << this->Allegiance << "." << endl;
            return;
        }
        cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << ((health / MAX_HEALTH) * attackStrength) << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - (health / MAX_HEALTH) * attackStrength);
    }
    else{
        cout << "Warrior " << this->getName() << " attacks " << opponent.getName() << " --- SLASH!!" << endl;
        cout << opponent.getName() << " takes " << ((health / MAX_HEALTH) * attackStrength) << " damage." << endl;
        opponent.setHealth(opponent.getHealth() - (health / MAX_HEALTH) * attackStrength);
    }
}