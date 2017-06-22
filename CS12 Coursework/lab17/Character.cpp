#include <iostream>
#include "Character.h"

using namespace std;

Character::Character(CharType type, const string &name, double health, double attackStrength){
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;
}
CharType Character::getType() const{
    return type;
}
const string & Character::getName() const{
    return name;
}
int Character::getHealth() const{
    return static_cast<int>(health);
}
void Character::setHealth(double h){
    health = h;
}
bool Character::isAlive() const{
    if(health > 0){
        return true;
    }
    return false;
}