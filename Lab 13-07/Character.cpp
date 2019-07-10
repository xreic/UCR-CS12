#include "Character.h"

Character::Character(HeroType type, const string& name, double health, double attackStrength): type(type), name(name), health(health), attackStrength(attackStrength){
}

HeroType Character::getType() const{
	return type;
}

const string& Character::getName() const{
	return name;
}
	
/* Returns the whole number of the health value (static_cast to int). */
int Character::getHealth() const{
	return static_cast<int> (health);
}

void Character::setHealth(double h){
	health = h;
}

/* Returns true if getHealth() returns an integer greater than 0, otherwise false */
bool Character::isAlive() const{
	if(health > 0)
		return true;
	
	return false;
}

void Character::attack(Character& oTarget){
}
