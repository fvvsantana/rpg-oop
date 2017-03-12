#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Character;
class Inventory;

class Item{
private:
    string name;
    double price;

protected:
    int attackPts;
    int defensePts;

public:
    //constructors:
    Item(string name, double price, int attackPts, int defensePts);
    Item(Item &item);

    //gets:
    string getName(){return name;}
    double getPrice(){return price;}
    virtual int getAttackPts()=0;
    virtual int getDefensePts()=0;

    //methods:
    virtual void use(Character &character, Inventory &inventory){};
    virtual void desUse(Character &character){};
};

#endif // ITEM_HPP
