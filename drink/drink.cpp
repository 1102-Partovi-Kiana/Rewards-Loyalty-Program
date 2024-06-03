//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the implementation for the drink file. 

#include "drink.h"
/// @cond
Drink::Drink(){
    size = 0;
    needsIce = false;
    needsStraw = false;
}
Drink::Drink(int sz, bool ice, bool straw, string name, int points, float cost) : MenuItem(name, points, cost){
    size = sz;
    needsIce = ice;
    needsStraw = straw;
}
Drink::Drink(const Drink& rhs){
    size = rhs.size;
    needsIce = rhs.needsIce;
    needsStraw = rhs.needsStraw;
}

int Drink::getSize() const{
    return size;
}
void Drink::setSize(const int sz){
    size = sz;
}

bool Drink::getNeedsStraw() const{
    return needsStraw; 
}
void Drink::setNeedsStraw(const bool straw){
    needsStraw = straw;
}

bool Drink::getNeedsIce() const{
    return needsIce;
}
void Drink::setNeedsIce(const bool ice){
    needsIce = ice;
}

ostream& Drink::displayItemInformation(ostream& stream) const {
    MenuItem::displayItemInformation(stream);
    if (getNeedsIce() == 1 && getNeedsStraw() == 1) {
        stream << "INCLUDE: ";
        stream << "Ice" << ", " << "Straw" << endl;
    } else if (getNeedsIce() == 0 && getNeedsStraw() == 1) {
        stream << "INCLUDE: ";
        stream << "Straw" << endl;
    } else if (getNeedsIce() == 1 && getNeedsStraw() == 0) {
        stream << "INCLUDE: ";
        stream << "Ice" << endl;
    }
    else if (getNeedsIce() !=  0 && getNeedsStraw() != 0 ) {
        return stream;
    } 
    stream << endl;
    return stream;
}

void Drink::calculateMenuItemCost() {
    float charges = 0.00;
    switch (size) {
        case 16:
            charges += 2.99;
            break;
        case 20:
            charges += 3.25;
            break;
        case 32:
            charges += 3.75;
            break;
    };
    if (getNeedsIce() == 1) {
        charges += 0.25;
    }
    if (getNeedsStraw() == 1) {
        charges += 0.75;
    }
    setCost(charges);
 }
/// @endcond