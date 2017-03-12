#include "../include/subCharacters.hpp"

Knight::Knight(string name, int power) : Character(name){
    Knight::power = power;
    if(Knight::power < 30) Knight::power = 30;
    else if(Knight::power > 100) Knight::power = 100;
}


int Knight::getDefensePoints(){
    return Character::getDefensePoints() + power;
}

void Knight::addPower(int n){
    power += n;
    if(power < 30) power = 30;
    else if(power > 100) power = 100;
}

Wizard::Wizard(string name, int wisdom) : Character(name){
    Wizard::wisdom = wisdom;
    if(Wizard::wisdom < 30) Wizard::wisdom = 30;
    else if(Wizard::wisdom > 100) Wizard::wisdom = 100;
}


int Wizard::getDefensePoints(){
    return Character::getDefensePoints() + wisdom;
}

void Wizard::addWisdom(int n){
    wisdom += n;
    if(wisdom < 30) wisdom = 30;
    else if(wisdom > 100) wisdom = 100;
}

Thief::Thief(string name, int stealth) : Character(name){
    Thief::stealth = stealth;
    if(Thief::stealth < 30) Thief::stealth = 30;
    else if(Thief::stealth > 100) Thief::stealth = 100;
}


int Thief::getAttackPoints(){
    return Character::getAttackPoints() + stealth;
}

void Thief::addStealth(int n){
    stealth += n;
    if(stealth < 30) stealth = 30;
    else if(stealth > 100) stealth = 100;
}
