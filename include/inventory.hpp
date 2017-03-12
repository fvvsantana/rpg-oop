#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Item;
class Character;

class Inventory{
private:
    int spaces;
    double gold;
    int itemsAmount;

    typedef struct{
        bool equiped;
        Item *item;
    } Space;
    list<Space> itemsList;
    list<Space>::iterator returnIterator(string name, bool &found);

    /*
    //helpers to the removeItem method:
    string currentItemName;
    bool sameName(Space &currentSpace);
    */

public:
    Inventory();
    ~Inventory();
    double getTotalGold(){return gold;}
    int getAvailableSpace(){return spaces - itemsList.size();}
    bool spendGold(double value);
    void earnGold(double value);
    bool setSpaces(int number);
    Item *searchItem(string name);
    bool insertItem(Item* newItem);
    bool removeItem(string name, Character &character);

    bool isEmpty(){return itemsList.empty();}
    int getTotalDefensePoints();
    int getTotalAttackPoints();
    bool useItem(string name, Character &character);
    bool desEquip(string name, Character &character);

    //void removeItem(string name);//
};

#endif // INVENTORY_HPP
