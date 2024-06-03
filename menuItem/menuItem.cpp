//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the implementation file for the constructors, getters, and setters. 

#include "./menuItem.h"


/// @cond

MenuItem::MenuItem(){
    itemName = "NONE";
    cost = -1;
    pointWorth = 0;
}
MenuItem::MenuItem(const MenuItem& rhs){
    itemName = rhs.itemName;
    cost = rhs.cost;
    pointWorth = rhs.pointWorth;
}
MenuItem::MenuItem(const string name, const int pts, const float val){
    cost = val;
    itemName = name;
    pointWorth = pts;
}

MenuItem::~MenuItem() {
}

float MenuItem::getCost() const{
    return cost;
}
void MenuItem::setCost(const float val){
    cost = val;
}

float MenuItem::operator+(const float& other) const {
    return cost + other;
}

string MenuItem::getItemName() const{
    return itemName;
}
void MenuItem::setItemName(const string name){
    itemName = name;
}

int MenuItem::getPointWorth() const{
    return pointWorth;
}
void MenuItem::setPointWorth(const int pts){
    pointWorth = pts;
}

/* void MenuItem::displayNameAndCost() {
    cout << getItemName() << " " << getCost() << endl;
} */

/* virtual void calculateMenuItemCost() = 0; */

ostream& MenuItem::displayItemInformation(ostream& stream) const {
    stream << getItemName() << " " << getCost() << endl;
    return stream;
}

ostream& operator << (ostream& o, const MenuItem& i) {
    i.displayItemInformation(o);
    return o;
}
// virtual void displayItemInformation() = 0; */
// don't need implementation for these in the parent of MenuItem.cpp because it is purely virtual
//implementation will just go in the children

///@endcond