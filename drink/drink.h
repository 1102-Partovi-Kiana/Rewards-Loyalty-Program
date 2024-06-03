//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the header file for the creation of the drink class. 

#ifndef DRINK_H
#define DRINK_H
#include "../menuItem/menuItem.h"
/*!
 * This is the Drink class, which inherits from the MenuItem class. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting drink size, if the customer wants a straw, and if they want ice
*/
class Drink : public MenuItem{
    int size; /*< int size of drink in fluid oz*/
    bool needsStraw; /*< bool value of if the customer wants a straw*/
    bool needsIce; /*< bool value of if the customer wants ice*/

    public:
        //! The default constructor. You can choose what to set values to.
        Drink();
        /*! The parameterized constructor
         \param size; int num oz
         \param straw; bool  user needs straw
         \param ice; bool user needs ice
        */
        Drink(int, bool, bool, string, int, float);
        /*! The copy constructor
         * Set all appropriate properties
         */
        Drink(const Drink&);

        /*! getter for size
         \return size; an int
        */
        int getSize() const;
        /*! setter for size
         \param size; int size
        */
        void setSize(const int);

        /*! getter for straw
         \return wantsStraw; a bool
        */
        bool getNeedsStraw() const;
        /*! setter for first name
         \param straw; bool to set needsStraw
        */
        void setNeedsStraw(const bool);

        /*! getter for straw
         \return wantsIce; a bool
        */
        bool getNeedsIce() const;
        /*! setter for needsIce
         \param ice; bool wantsIce
        */
        void setNeedsIce(const bool);
        virtual ostream& displayItemInformation(ostream&) const override;
        // void displayItemInformation() override;
        void calculateMenuItemCost() override;

};
#endif