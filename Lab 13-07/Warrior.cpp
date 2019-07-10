#include "Warrior.h"

Warrior::Warrior(const string& wName, double wHealth, double wAttackStrength, const string& wAllegiage): Character(WARRIOR, wName, wHealth, wAttackStrength), allegiance(wAllegiage){
}

void Warrior::attack(Character& oTarget){
    if(oTarget.getType() != 0){
        double damageDealt;
        damageDealt = ((this->health / MAX_HEALTH) * this->attackStrength);
        
        cout << "Warrior " << this->name << " attacks " << oTarget.getName() << " --- SLASH!!" << endl;
        cout << oTarget.getName() << " takes " << damageDealt << " damage." << endl;
        oTarget.setHealth(oTarget.getHealth() - damageDealt);
        return;
    }
    else{
        Warrior& wTarget = dynamic_cast<Warrior&>(oTarget);
        if(this->allegiance == wTarget.allegiance){
            cout << "Warrior " << this->name << " does not attack " << "Warrior " << wTarget.name << "." << endl << "They share an allegiance with " << this->allegiance << "." << endl;
            return;
        }
        else{
            double damageDealt;
            damageDealt = ((this->health / MAX_HEALTH) * this->attackStrength);
            
            cout << "Warrior " << this->name << " attacks " << wTarget.name << " --- SLASH!!" << endl;
            cout << wTarget.name << " takes " << damageDealt << " damage." << endl;
            wTarget.setHealth(wTarget.getHealth() - damageDealt);
            return;
        }
    }
}
