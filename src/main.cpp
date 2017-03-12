/*
 * brief:
 * Attributes:
 * accuracy, stealth, wisdom, power: 30-100;
 * strength, speed, dexterity, constituion: 1-100;
 * strength + speed + dexterity + constituion <= 100;
 * defensePts: 1-20;
 * attackPts: 1-9;
 * restorePts: 1-20;
 * weight: 1-20;
 */

#include <iostream>
#include <string>
#include "../include/subCharacters.hpp"
#include "../include/subItems.hpp"

using namespace std;

int main(){
    Thief ju("ju", 50);
    ju.setSpeed(50);

    Armor shield("shield", 50, 13, 20);
    Weapon arc("arc", 50, 13, 20);
    HealthPotion hp("hp", 50, 20);
    ManaPotion mp("mp", 50, 20);

    ju.setSpaces(10);

    ju.insertItem(&shield);
    ju.insertItem(&arc);
    ju.insertItem(&hp);
    ju.insertItem(&mp);

    //cout << "defense pts: " << ju.getDefensePoints() << endl;
    //cout << "defense pts: " << ju.getDfPts() << endl;
    //cout << "attack pts: " << ju.getAtPts() << endl;
    cout << "speed: " << ju.getSpeed() << endl;

    ju.useItem("shield");
    ju.useItem("arc");
    ju.useItem("hp");
    ju.useItem("mp");

    //cout << "defense pts: " << ju.getDefensePoints() << endl;
    //cout << "defense pts: " << ju.getDfPts() << endl;
    //cout << "attack pts: " << ju.getAtPts() << endl;
    cout << "speed: " << ju.getSpeed() << endl;

    ju.removeItem("shield");
    ju.removeItem("arc");
    ju.removeItem("hp");
    ju.removeItem("mp");

    cout << "speed: " << ju.getSpeed() << endl;
    return 0;
}
