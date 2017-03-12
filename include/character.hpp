#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <cstdlib>
#include <time.h>
#include <new>

using namespace std;

class Inventory;
class Item;
class Potion;

enum Attack{
    MISS,
    NORMAL,
    CRITICAL,
    KILL,
    CRITICALKILL
};

class Character{
private:
    string alias;
    Inventory *myItems;
    int hp;
    int mp;

protected:
    int xp;
    int strength;
    int speed;
    int dexterity;
    int constitution;
    int accuracy;
    int power;

    //methods:
    int getDefensePoints();
    int getAttackPoints();


public:
    Character(string name);
    ~Character();

    virtual Attack attack(Character &enemy);
    void addXp(int n);
    void addMp(int n){mp += n;}
    void addHp(int n);
    bool takeDamage(int damage);
    bool insertItem(Item* newItem);
    bool useItem(string name);
    bool desEquip(string name);
    bool usePotion(Potion* newPotion);
    bool removeItem(string name);


    //getters:
    string getName();
    int getXp(){return xp;}
    int getHp(){return hp;}
    int getSpeed(){return speed;}

    //setters:
    void setStrength(int strength);
    void setSpeed(int speed);
    void setDexterity(int dexterity);
    void setConstitution(int constitution);
    void setAccuracy(int accuracy);
    void setPower(int power);
    bool setSpaces(int number);
};
#endif // CHARACTER_HPP
