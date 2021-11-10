#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include "Fighter.h"

//=======
//Implementing Constructors

Fighter::Fighter(string init_name, int init_strength, double init_agility) {
    fighterName = init_name;
    strength = init_strength;
    agility = init_agility;
    hp = init_strength * init_agility;
}