#ifndef FIGHTERS
#define FIGHTERS

#include <string>
using namespace std;

// randPct: void -> double
// purpose: expects nothing
// returns a value from 0.01 to 1.00 in increments used for fighting
double randPct();

class Fighter {
    public:
        //constructor
        Fighter(string init_name, int init_strength, double init_agility, double init_hp);
    
    private:
        string fighterName;
        int strength;
        double agility;
        double hp;
};

#endif