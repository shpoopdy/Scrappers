#ifndef FIGHTER
#define FIGHTER

#include <string>
using namespace std;

// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments used for fighting
double randPct();

class Fighter {
    public:
        //constructor
        Fighter(string init_name, int init_strength, double init_agility);

        //accessors
        string getName() const;
        int getStrength() const;
        double getAgility() const;
        double getHp() const;

        //mutators
        void resetHp();

        //other methods
        void printFighter() const;

        void battle(Fighter& opponent);
    
    private:
        string fighterName;
        int strength;
        double agility;
        double hp;
};

#endif