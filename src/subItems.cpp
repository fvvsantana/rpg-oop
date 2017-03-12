#include "../include/subItems.hpp"
#include "../include/character.hpp"
#include "../include/inventory.hpp"
#include <cmath>

Weapon::Weapon(string name, double price, int attackPts, double range) : Item::Item(name, price, attackPts, 0){
    this->range = range;
}

Weapon::Weapon(Weapon &weapon) : Item::Item(weapon){
    this->range = weapon.range;
}

Armor::Armor(string name, double price, int defensePts, double weight) : Item::Item(name, price, 0, defensePts){
    if(weight > 20) this->weight = 20;
    else if(weight < 1) this->weight = 1;
    else this->weight = weight;
}

Armor::Armor(Armor &armor) : Item::Item(armor){
    this->weight = armor.weight;
}

void Armor::use(Character &character, Inventory &inventory){
    int newSpeed = character.getSpeed() * exp((-1)*pow((double)weight/20, 2));
    if(newSpeed < 1) newSpeed = 1;
    character.setSpeed(newSpeed);
}
void Armor::desUse(Character &character){
    int oldSpeed = character.getSpeed() * exp(pow((double)weight/20, 2));
    if(oldSpeed > 100) oldSpeed = 100;
    character.setSpeed(oldSpeed);
}

Potion::Potion(string name, double price, int restorePts) : Item::Item(name, price, 0, restorePts){
    this->restorePts = restorePts;
};

Potion::Potion(Potion &potion) : Item::Item(potion){};

Potion::~Potion(){

}

ManaPotion::ManaPotion(string name, double price, int restorePts) : Potion::Potion(name, price, restorePts){};

ManaPotion::~ManaPotion(){

}

void ManaPotion::use(Character &character, Inventory &inventory){
    character.addMp(getRestorePts());
    inventory.removeItem(getName(), character);
}

HealthPotion::HealthPotion(string name, double price, int restorePts) : Potion::Potion(name, price, restorePts){};

HealthPotion::~HealthPotion(){

}

void HealthPotion::use(Character &character, Inventory &inventory){
    character.addHp(getRestorePts());
    inventory.removeItem(getName(), character);
}
