#include "../include/inventory.hpp"
#include "../include/item.hpp"
#include "../include/subItems.hpp"
#include <typeinfo>

Inventory::Inventory(){
    spaces = 0;
    gold = 0;
    itemsAmount = 0;
}

Inventory::~Inventory(){
}

bool Inventory::spendGold(double value){
    if(gold < value){
        return false;
    }
    gold = gold - value;
    return true;
}

void Inventory::earnGold(double value){
    gold += value;
}

bool Inventory::setSpaces(int number){
    if(number <= itemsAmount){
        return false;
    }
    spaces = number;
    return true;
}

Item* Inventory::searchItem(string name){
    list<Space>::iterator it = itemsList.begin();
    while(it != itemsList.end()){
        if((it->item)->getName() == name) return it->item;
        it++;
    }
    return NULL;
}

bool Inventory::insertItem(Item* newItem){
    if(newItem && (itemsAmount < spaces) && !searchItem(newItem->getName())){
        Space newSpace = {false, newItem};
        itemsList.push_back(newSpace);
        itemsAmount++;
        return true;
    }
    return false;
}

bool Inventory::removeItem(string name, Character &character){
    if(itemsList.empty()) return false;
    bool found;
    list<Space>::iterator it = returnIterator(name, found);
    if(!found) return false;
    //remove item:
    (it->item)->desUse(character);
    itemsList.erase(it);
    itemsAmount--;
    return true;
}

list<Inventory::Space>::iterator Inventory::returnIterator(string name, bool &found){
    if(itemsList.empty()){
        found = false;
        list<Space>::iterator it;
        return it;
    }

    list<Space>::iterator it = itemsList.begin();
    if((it->item)->getName() == name){
        found = true;
        return it;
    }

    while(it != itemsList.end()){
        if((it->item)->getName() == name){
            found = true;
            return it;
        }
        it++;
    }
    found = false;
    return it;
}

int Inventory::getTotalDefensePoints(){
    list<Space>::iterator it = itemsList.begin();
    int totalDefensePoints = 0;
    while(it != itemsList.end()){
        if(it->equiped) totalDefensePoints += it->item->getDefensePts();
        it++;
    }
    return totalDefensePoints;
}

int Inventory::getTotalAttackPoints(){
    list<Space>::iterator it = itemsList.begin();
    int totalAttackPoints = 0;
    while(it != itemsList.end()){
        if(it->equiped) totalAttackPoints += it->item->getAttackPts();
        it++;
    }
    return totalAttackPoints;
}

//changes equiped member of space which contains an item whose name is name:
bool Inventory::useItem(string name, Character &character){
    //equiping item:
    bool found;
    list<Space>::iterator it = returnIterator(name, found);
    if(!found) return false;
    //check if there is already 1 or more equipedArmors in the inventory:
    if(typeid(*(it->item)) == typeid(Armor)){
        list<Space>::iterator it2 = itemsList.begin();
        while(it2 != itemsList.end()){
            if((typeid(*(it2->item)) == typeid(Armor)) && (it2->equiped == true)) return false;
            it2++;
        }
    //check if there is already 2 or more equipedWeapons in the inventory:
    }else if(typeid(*(it->item)) == typeid(Weapon)){
        list<Space>::iterator it2 = itemsList.begin();
        int nEquipedWeapons = 0;
        while(it2 != itemsList.end()){
            if((typeid(*(it2->item)) == typeid(Weapon)) && (it2->equiped == true)) nEquipedWeapons++;
            if(nEquipedWeapons >= 2) return false;
            it2++;
        }
    }
    it->equiped = true;
    //---------------

    //using item:
    (it->item)->use(character, *this);
    return true;
}

//changes equiped member of space which contains an item whose name is name:
//returns false when the item is not found.
bool Inventory::desEquip(string name, Character &character){
    //desequiping item:
    bool found;
    list<Space>::iterator it = returnIterator(name, found);
    if(!found) return false;
    it->equiped = false;
    //---------------

    //desusing item:
    (it->item)->desUse(character);
    return true;
}

/*
bool Inventory::sameName(Space &currentSpace){
    return (currentItemName == currentSpace.item->getName());
}

void Inventory::removeItem(string name){
    currentItemName = name;
    itemsList.remove_if(sameName);
}
*/
