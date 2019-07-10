#ifndef WARRIOR_H
#define WARRIOR_H

#include "Character.h"

class Warrior: public Character{
    private:
        string allegiance;
        
    public:
        Warrior(const string& wName, double wHealth, double wAttackStrength, const string& wAllegiage);

        void attack(Character& );
};

#endif
