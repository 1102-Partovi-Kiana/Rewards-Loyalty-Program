//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the header file for the creation of the customer class. 

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <iomanip>
using namespace std;
#include "../menuItem/menuItem.h"
#define STARTSIZEORDER 1


#define MAX_SIZE_ORDER 50
/*!
 * This is the Customer class. 
 * It must have a default constructor, parameterized constructor, and copy constructor
 * It is responsible for getting and setting customer first name, last name, the loyalty number
 * the number of loyalty points associated with a customer and the number of items in their current order
 * and an array of MenuItem that a customer has added to their order (max size 50)
*/
class Customer{
    string customerFirst, customerLast; /*< string value of first name and last name*/
    long int loyaltyNumber; /*< long int value of loyalty number*/
    mutable long int numberLoyaltyPoints; /*< long int value of number loyalty points customer has*/
    //mutable int numItemsInOrder; /*< int value of number items in current order*/
    mutable float orderCost;
    //MenuItem** currentOrder;
    //MenuItem** currentOrder = new MenuItem*[MAX_SIZE_ORDER]; /*< an array of menuItems */

    public:
        mutable int counter = 0;
        //! The default constructor. You can choose what to set values to.
        Customer();
        dynamicArray<MenuItem*> currentOrder;
        /*! The parameterized Constructor
         \param first; string first name to set Customer first
         \param last; string last name to set customer last
         \param id; long int loyalty id
         \param numPts; long int number of loyalty points that the customer has 
        */
        Customer(const string, const string, const long int, const long int);
        /*! The copy constructor
         * Make sure you create a loop using the old patron's number of rides to set all the rides in the array
         * Set all appropriate properties
         */
        Customer(const Customer&);
        /*! getter for first name
        \return first name; a string
        */
        //~Customer();  // don't use override because we are not inheriting 
        string getCustomerFirst() const;
        /*! setter for first name
         \param first; string first name to set patron first
        */
        void setCustomerFirst(const string);

        /*! getter for last name
         \return last name; a string last name for a set patron
        */
        string getCustomerLast() const;
        /*! setter for last name
         \param last name; a string last name
        */
        void setCustomerLast(const string);
        /*! getter for loyalty number
         \return loyalty number; an int
        */
        long int getLoyaltyNumber() const;
        /*! setter for first name
         \param loyaltyNumber; int loyalty number
        */
        void setLoyaltyNumber(const long int);

        /*! getter for customer's loyalty points
         \return number of loyalty points; an int
        */
        long int getNumberLoyaltyPoints() const;
        /*! setter for customer's loyalty points
         \param numPoints; integer number of points
        */
        void setNumberLoyaltyPoints(const long int) const;

        /*! getter for current order
         \return customerOrder; a pointer to a menu item array
        */
        dynamicArray<MenuItem*>& getCurrentOrder();
        /*! setter for customer's order (kind of). Adds the new menuItem to the end of the order array and increments the number of items
         \param menuItem; a pointer to a MenuItem object
        */
        void addItemToOrder(const MenuItem&);
        
        /*! getter for number of items in the order
         \return number of items in customer order
        */
        //int getNumItemsInOrder() const;
        /*! setter for number of items in order so that they can be reset to 0 every time the program loops in main
         \param numItems; the integer number of items in the customer's order
        */
       //void setNumItemsInOrder(const int) const;

        /*! sums each item's cost from the current order and applies a 8.27% tax to it, which is returned as the customer's total. */
        float calculateCost() const;
        /*! displays the current order menu to the user when it's time to check out and outputs the total after calling calculate cost*/
        // virtual void displayOrder() const;
        /*!Displays the welcome message and number of loyalty*/
        void displayCustomerInformation() const ;

        void clearOrder();

        void setOrderCost(float newCost);

        float getOrderCost() const;
        friend ostream& operator << (ostream&, const Customer&);
};
#endif