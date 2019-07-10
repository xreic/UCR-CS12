#ifndef ELF_H
#define ELF_H

#include "Character.h"

class Elf: public Character{
    private:
        string family;
        
    public:
        Elf(const string& eName, double eHealth, double eAttackStrength, const string& eFamily);

        void attack(Character& );
};

#endif
