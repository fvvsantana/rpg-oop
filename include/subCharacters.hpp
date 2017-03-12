#ifndef SUBCHARACTERS_HPP
#define SUBCHARACTERS_HPP

#include <string>
#include "character.hpp"


using namespace std;

class Knight : public Character{
protected:
    virtual int getDefensePoints();

public:
    Knight(string name, int power);
    void addPower(int n);

};

class Wizard : public Character{
protected:
    virtual int getDefensePoints();
    int wisdom;

public:
    Wizard(string name, int wisdom);
    void addWisdom(int n);

};

class Thief : public Character{
protected:
    virtual int getAttackPoints();
    int stealth;

public:
    Thief(string name, int stealth);
    void addStealth(int n);

};

#endif //SUBCHARACTERS_HPP
