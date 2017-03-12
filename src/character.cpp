#include "../include/character.hpp"
#include "../include/inventory.hpp"
#include "../include/item.hpp"
#include "../include/subItems.hpp"

Character::Character(string name){
    Character::alias = name;
    Character::myItems = (Inventory *) new Inventory;
    Character::hp = 100;
    Character::xp = 1;
    Character::strength = 1;
    Character::speed = 1;
    Character::dexterity = 1;
    Character::constitution = 1;
    Character::accuracy = 30;
    Character::power = 30;
}

Character::~Character(){
    delete myItems;
}

void Character::addXp(int n){
    xp += n;
    if(xp > 100) xp = 100;
}

void Character::addHp(int n){
    hp += n;
    if(hp > 100) hp = 100;
}

//returns false if the character dies. Returns true if he doesn't:
bool Character::takeDamage(int damage){
    hp -= damage;
    if(hp > 0){
        return true;
    }
    return false;
}

void Character::setStrength(int strength){
    if(strength < 1){
        Character::strength = 1;
    }else if(strength>100){
        Character::strength = 100;
    }else{
        Character::strength = strength;
    }

    if(Character::strength + Character::speed + Character::dexterity + Character::constitution > 100){
        Character::strength = 100 - (Character::speed + Character::dexterity + Character::constitution);
    }
}

void Character::setSpeed(int speed){
    if(speed < 1){
        Character::speed = 1;
    }else if(speed>100){
        Character::speed = 100;
    }else{
        Character::speed = speed;
    }

    if(Character::strength + Character::speed + Character::dexterity + Character::constitution > 100){
        Character::speed = 100 - (Character::strength + Character::dexterity + Character::constitution);
    }
}

void Character::setDexterity(int dexterity){
    if(dexterity < 1){
        Character::dexterity = 1;
    }else if(dexterity>100){
        Character::dexterity = 100;
    }else{
        Character::dexterity = dexterity;
    }

    if(Character::strength + Character::speed + Character::dexterity + Character::constitution > 100){
        Character::dexterity = 100 - (Character::strength + Character::speed + Character::constitution);
    }
}

void Character::setConstitution(int constitution){
    if(constitution < 1){
        Character::constitution = 1;
    }else if(constitution>100){
        Character::constitution = 100;
    }else{
        Character::constitution = constitution;
    }

    if(Character::strength + Character::speed + Character::dexterity + Character::constitution > 100){
        Character::constitution = 100 - (Character::strength + Character::speed + Character::dexterity);
    }
}

void Character::setAccuracy(int accuracy){
    if(accuracy < 30){
        Character::accuracy = 30;
    }else if(accuracy>100){
        Character::accuracy = 100;
    }else{
        Character::accuracy = accuracy;
    }
}

void Character::setPower(int power){
    if(power < 30){
        Character::power = 30;
    }else if(power>100){
        Character::power = 100;
    }else{
        Character::power = power;
    }
}

int Character::getDefensePoints(){
    return (constitution * 0.5 + dexterity * 0.3 + speed * 0.2 + myItems->getTotalDefensePoints()) * xp/2;
}

int Character::getAttackPoints(){
    return (strength* 0.5 + dexterity * 0.3 + speed * 0.2 + myItems->getTotalAttackPoints()) * xp/3;
}


Attack Character::attack(Character &enemy){
    srand((unsigned) time(NULL));
    //calculates the normal damage:
    int normalDamage = (getAttackPoints()-enemy.getDefensePoints()) + rand()%11 - 5;
    if(normalDamage <= 0) normalDamage = 1;

    //decides if the attack will be critical:
    if(rand()%100 < xp){ //critical
        if(enemy.takeDamage(2 * normalDamage)) return CRITICAL;
        return CRITICALKILL; //if he dies
    }else{ //not critical
        //decides if will miss or not:
        if(rand()%3){ //normal
            if(enemy.takeDamage(normalDamage)) return NORMAL;
            return KILL; //if he dies
        }
        return MISS;
    }
}

bool Character::insertItem(Item* newItem){
    return myItems->insertItem(newItem);
}

bool Character::useItem(string name){
    return myItems->useItem(name, *this);
}

bool Character::desEquip(string name){
    return myItems->desEquip(name, *this);
}

bool Character::usePotion(Potion* newPotion){
    if(!newPotion) return false;
    newPotion->use(*this, *myItems);
    return true;
}

bool Character::removeItem(string name){
    return myItems->removeItem(name, *this);
}

bool Character::setSpaces(int number){
    return myItems->setSpaces(number);
}
