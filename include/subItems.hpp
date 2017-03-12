#ifndef SUBITEMS_HPP
#define SUBITEMS_HPP

#include <string>
#include "item.hpp"


class Weapon : public Item{
protected:
    double range;

public:
    Weapon(string name, double price, int attackPts, double range);
    Weapon(Weapon &weapon);

    int getDefensePts(){return 0;}
    int getAttackPts(){return attackPts;}
    double getRange(){return range;}
};

class Armor : public Item{
protected:
    double weight; //

public:
    Armor(string name, double price, int defensePts, double weight);
    Armor(Armor &armor);

    int getDefensePts(){return defensePts;}
    int getAttackPts(){return 0;}
    double getWeight(){return weight;}
    virtual void use(Character &character, Inventory &inventory);
    virtual void desUse(Character &character);
};


class Potion : public Item{
private:
    int restorePts;

protected:
    int getRestorePts(){return restorePts;}

public:
    Potion(string name, double price, int restorePts);
    Potion(Potion &potion);
    ~Potion();//

    int getDefensePts(){return restorePts;}
    int getAttackPts(){return 0;}
    virtual void use(Character &character, Inventory &inventory)=0;
};

class ManaPotion : public Potion{
public:
    ManaPotion(string name, double price, int restorePts);
    ~ManaPotion();
    virtual void use(Character &character, Inventory &inventory);
};

class HealthPotion : public Potion{
public:
    HealthPotion(string name, double price, int restorePts);
    ~HealthPotion();
    virtual void use(Character &character, Inventory &inventory);
};

#endif //SUBITEMS_HPP
