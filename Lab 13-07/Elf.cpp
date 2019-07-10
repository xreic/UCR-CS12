#include "Elf.h"

Elf::Elf(const string& eName, double eHealth, double eAttackStrength, const string& eFamily): Character(ELF, eName, eHealth, eAttackStrength), family(eFamily){
}

void Elf::attack(Character& oTarget){
    if(oTarget.getType() != 1){
        double damageDealt;
        damageDealt = ((this->health / MAX_HEALTH) * this->attackStrength);
        
        cout << "Elf " << this->name << " shoots an arrow at " << oTarget.getName() << " --- TWANG!!" << endl;
        cout << oTarget.getName() << " takes " << damageDealt << " damage." << endl;
        oTarget.setHealth(oTarget.getHealth() - damageDealt);
        return;
    }
    else{
        Elf& eTarget = dynamic_cast<Elf&>(oTarget);
        if(this->family == eTarget.family){
            cout << "Elf " << this->name << " does not attack " << "Elf " << eTarget.name << "." << endl << "They are both members of the " << this->family << " family." << endl;
            return;
        }
        else{
            double damageDealt;
            damageDealt = ((this->health / MAX_HEALTH) * this->attackStrength);
            
            cout << "Elf " << this->name << " shoots an arrow at " << eTarget.name << " --- TWANG!!" << endl;
            cout << eTarget.name << " takes " << damageDealt << " damage." << endl;
            eTarget.setHealth(eTarget.getHealth() - damageDealt);
            return;
        }
    }
}
