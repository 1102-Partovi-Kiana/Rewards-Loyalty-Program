//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the header file for the creation of the menu item class. 

#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;
#define MAX_NUMBER_INGREDIENTS 50
#include "../dynamicArray/dynamicArray.cpp"
/*!
 * This is the MenuItem class. It is inherited by Food and Drink
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting the item's name, cost, and point worth
*/
class MenuItem{
    protected:
        float cost;/*< float value item cost*/
        string itemName; /*< string value item name*/
        int pointWorth; /*< int value point worth*/

    public:
        //! The default constructor. You can choose what to set values to.
        MenuItem();
        /*! The parameterized Constructor
         \param cost; float value cost of item
         \param itemName; string item name
         \param pointWorth; number of loyalty points good can be exchanged for 
        */
        MenuItem(const string, const int, const float);
        /*! The copy constructor
         * Set all appropriate properties
         */
        MenuItem(const MenuItem&);
        virtual ~MenuItem();
    
        
        /*! getter for cost
        \return cost; a float
        */
        float getCost() const;
        /*! setter for cost
         \param cost; integer value of cost to set
        */
        void setCost(const float);

        /*! getter for item name
        \return name; a string
        */
        string getItemName() const;
        /*! setter for item name
         \param name; string value of item name
        */
        void setItemName(const string);
        
        /*! getter for point worth
        \return pointWorth; an int
        */
        int getPointWorth() const;
        /*! setter for pointWorth
         \param pointWorth; integer value of points
        */
        void setPointWorth(const int);

        //new functions part 1
        // void displayNameAndCost();
        virtual void calculateMenuItemCost() = 0;
        // virtual ostream& displayItemInformation(ostream&) = 0;

        float operator + (const float&) const;
        virtual ostream& displayItemInformation(ostream&) const;
        friend ostream& operator << (ostream&, const MenuItem&);

};
#endif