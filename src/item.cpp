#include "../include/item.hpp"


Item::Item(string name, double price, int attackPts, int defensePts){
    //initialize attributes:
    this->name = name;
    this->price = price;

    if(attackPts<1){
        this->attackPts = 1;
    }else if(attackPts>9){
        this->attackPts = 9;
    }else{
        this->attackPts = attackPts;
    }

    if(defensePts<1){
        this->defensePts = 1;
    }else if(defensePts>20){
        this->defensePts = 20;
    }else{
        this->defensePts = defensePts;
    }
}

Item::Item(Item &item){
    name = item.name;
    price = item.price;
    defensePts = item.defensePts;
    attackPts = item.attackPts;
}
