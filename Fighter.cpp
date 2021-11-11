#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <ctime>
#include "Fighter.h"

//=======
//Implementing Constructor

Fighter::Fighter(string init_name, int init_strength, double init_agility) {
    fighterName = init_name;
    strength = init_strength;
    agility = init_agility;
    hp = init_strength * init_agility;
}

//======
//Implementing Accessors

string Fighter::getName() const {
    return fighterName;
}
int Fighter::getStrength() const {
    return strength;
}
double Fighter::getAgility() const {
    return agility;
}
double Fighter::getHp() const {
    return hp;
}

//=======
//Implementing mutators
void Fighter::resetHp() {
    hp = strength * agility;
}

void Fighter::setHp(double new_hp) {
    hp = new_hp;
}

//========
//Implementing other methods
void Fighter::printFighter() const {
    cout << "Fighter name: " << fighterName << endl
         << "strength: " << strength << endl
         << "agility: " << agility << endl
         << "Hp: " << hp << endl;
}

void Fighter::battle(Fighter& opponent) {
    //Assigns health from each Fighter
    double my_health = this->getHp();
    double enemy_health = opponent.getHp();

    //Returns a value from 0.01 to 1.00 to determine damage.
    double randPct_me = randPct();
    double randPct_enemy = randPct();

    //Damage is based on Fighter health and randPct
    double my_damage = my_health * randPct_me;
    double enemy_damage = enemy_health * randPct_enemy;

    cout << this->getName() << " has dealt " << my_damage
         << " damage to " << opponent.getName() << endl;
    cout << opponent.getName() << " has dealt " << enemy_damage
         << " damage to " << this->getName() << endl;

    //Damage is assigned
    if(my_damage >= enemy_health) {
        enemy_health = 0.0;
        opponent.setHp(enemy_health);
    }
    else {
        enemy_health -= my_damage;
        opponent.setHp(enemy_health);
    }

    if(enemy_damage >= my_health) {
        my_health = 0.0;
        this->setHp(my_health);
    }
    else {
        my_health -= enemy_damage;
        this->setHp(my_health);
    }

    //==========
    //Checking for knock outs
    if(my_health == 0.0) {
        cout << "OH! Looks like " << this->getName()
             << " was knocked out!" << endl;
    }
    else if(enemy_health == 0.0) {
        cout << "OH! Looks like " << opponent.getName()
             << " was knocked out!" << endl;
    }

    //==========
    //Determining Winner
    if(my_health > enemy_health) {
        cout << "WE HAVE A WINNER AND IT IS " << this->getName() << "!" << endl;
    }
    else if(enemy_health > my_health) {
        cout << "WE HAVE A WINNER AND IT IS " << opponent.getName() << "!" << endl;
    }
}

double randPct()
{
    double return_val;
    return_val = (rand() % 100 + 1) * 0.01;
    return return_val;
}