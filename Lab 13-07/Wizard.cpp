#include "Wizard.h"

Wizard::Wizard(const string& wName, double wHealth, double wAttackStrength, const int& wRank): Character(WIZARD, wName, wHealth, wAttackStrength), rank(wRank){
}

void Wizard::attack(Character& oTarget){
    if(oTarget.getType() != 2){
        cout << "Wizard " << this->name << " attacks " << oTarget.getName() << " --- POOF!!" << endl;
        cout << oTarget.getName() << " takes " << this->attackStrength << " damage." << endl;
        oTarget.setHealth(oTarget.getHealth() - this->attackStrength);
        return;
    }
    else{
        Wizard& wzTarget = dynamic_cast<Wizard&>(oTarget);

        double damageDealt;
        damageDealt = this->attackStrength * (static_cast<double>(this->rank) / wzTarget.rank);

        cout << "Wizard " << this->name << " attacks " << wzTarget.name << " --- POOF!!" << endl;
        cout << wzTarget.name << " takes " << damageDealt << " damage." << endl;
        wzTarget.setHealth(wzTarget.getHealth() - damageDealt);
        return;
    }
}
