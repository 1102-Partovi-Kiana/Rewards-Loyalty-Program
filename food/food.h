//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the header file for the creation of the food class. 

#ifndef FOOD_H
#define FOOD_H

#include "../menuItem/menuItem.h"
#include "../dynamicArray/dynamicArray.h"


/*!
 * This is the Food class which inherits from MenuItem. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting ingredients, and getting the number of ingredients 
*/
class Food : public MenuItem{
    //string ingredients[MAX_NUMBER_INGREDIENTS]; /*< an array of strings for each ingredient*/
    //string* ingredients = new string[MAX_NUMBER_INGREDIENTS]; // this is correct
    dynamicArray<string> ingredients;
    int numberIngredients = 0; /*< integer value number of ingredients in item*/
    //string availableExtras[MAX_NUMBER_INGREDIENTS];
    // string* availableExtras[MAX_NUMBER_INGREDIENTS]
    //string* availableExtras = new string[MAX_NUMBER_INGREDIENTS];  // this is correct
    dynamicArray<string> availableExtras;
    int numAvailableExtras = 0;
    public: 
        //! The default constructor. You can choose what to set values to.
        Food();
        /*! The parameterized Constructor
         \param item; a pointer the first element in the ingredient array
         \param numIngredients; an integer number of ingredients in item
        */
        Food(const string*, const int, const string, const int, float);
        /*! The copy constructor
         * Set all appropriate properties
         */
        Food(Food&);
       // ~Food() override;

        /*! getter for  ingredient array
        \return ingredients; a pointer to an array of strings
        */
        dynamicArray<string>& getIngredients();
        /*! setter for ingredients; adds new ingredient at end of ingredient array and increments number of ingredients
         \param ingredient; a string to add to ingredients array
        */
        void addIngredient(const string);

        /*! getter for number of ingredients
        \return numIngredients; an int
        */
        int getNumberIngredients() const;

        virtual ostream& displayItemInformation(ostream&) const override;
        // void displayItemInformation() override;
        dynamicArray<string>& getAvailableExtras();
        int getNumExtras();
        void setAvailableExtras();  // don't need the paramter for this setter
        void calculateMenuItemCost() override;
        void setNumAvailableExtras(int);
};
#endif