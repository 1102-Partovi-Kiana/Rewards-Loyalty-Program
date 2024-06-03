//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This file runs the functionality of the program, prompting the user of their participation in the e program. 

/*
 * Purpose: Create restaurant ordering system that tracks customer loyalty
 * Max number of customers for this program is 1000
 * Max number of menuItems is 100
 * Max number of ingredients is 50
 * NOTE: only include NECESSARY .h files and built in libraries in cpp files (you only need fstream in driver for example)
*/

#include "../customer/customer.h"
#include "../drink/drink.h"
#include "../food/food.h"

#include <fstream>


#define MAX_NUM_CUSTOMERS 1000

/*!
 * Provides the logic for adding a new customer to the database, or to enter their loyalty number
 * Ask user if they are a member of the loyalty program, capture their choice using getUserCharChoice
 * If the user enters anything other 'y' or 'n' or 'Y' or 'N', continue trying to get user input
 * If the user says that they are a member, prompt them for their loyalty number. Loop through every customer
 * in the customers array and check if their loyalty number matches the loyalty number provided by user
 * If a match is found, display the customer's information and return the index of the customer that was found
 * If a match is not found, prompt the user repeatedly if they would like to join the loyalty program until they enter y or n
  * If they choose not to join, return -1
 * If they choose to join, create a new customer using create customer, and insert that customer into the customers array
 * then increment the number of customers, display the customer's information, and return the index of the new member (numCustomers -1)
 * use the displayCustomerInformation method to display customer information
 \param customers; a pointer to the customer array;  passed in from main
 \param numCustomers; a pointer to the number of customers in array; passed in from main
 \return index of the customer in customer array if added to loyalty program, -1 otherwise
*/
int runLoyaltyProgram(dynamicArray<Customer*>&);

/*!
 * Overwrites loyalty.txt every time a new order is started, so that new customers are added to the database
 * Open an output stream, then loop through each customer and output their loyalty number, first name, last name and number of points
 * Don't forget to put spaces in between each variable when you output!
 \param customers; a pointer to the customer array, passed in from main
 \param numCustomers; an int representing the number of customers in the array
*/
void overwriteLoyaltyDatabase(dynamicArray<Customer*>&); // keep it a pointer

/*!
 * Ask the user if they want to use their points; if they don't enter y or n or Y or N, prompt again
 * Gather user input
 * If the user wants to use their points return True
 * If the user does not want to use their points, tell them they will be banked and return false.
 \param customers; a pointer to the array of customers
 \return whether the user wants to use their points or not
*/
bool pointSystemPrompt(const Customer&);

/*!
 * Displays rewards and their point values.
*/
void displayPointRedemptionMenu();

/*!
 * Displays a prompt for a new user to input user loyalty information (7 digit number, first name, last name)
*/
void displayLoyaltyInformationPrompt();

/*!
 * Gathers integer userInput 
*/
template <typename T>
T getUserChoice();

//int getUserIntChoice();

/*!
 * Gathers char userInput
*/
//char getUserCharChoice();

/*!
 * gathers string user input
*/
//string getUserStringEntry();

/*!
 * Displays the join message, calls displayPointRedemptionMenu, and the prompts user if they'd like to join
*/
void displayMemberJoin();

/*!
 * Prompts for user input using displayMenuItems
 * Gets user input using getUser method
 * Adds input repeatedly using addItemToOrder until user chooses to exit
 \param customer; a pointer to the current customer that has been passed in from main
*/
dynamicArray<MenuItem*> placeOrder(const Customer&);

/*!
 * displays contents of the restaurant menu
*/
void displayMenuItems();


/*!
 * Prompt the user for their loyalty information
 * get each entry
 * Use the customer parameterized constructor to create the customer
 * return the customer
*/
Customer* createCustomer();

/*!
 * Opens loyalty.txt and reads customer info from it
 * Constructs a customer with info
 * Adds the customer to the passed in customer array
 * For each customer in the file, increments a counter
 * \param customerArray; an array of Customer objects
 * \return the number of customers read from the file.
*/
void getLoyaltyDatabase(dynamicArray<Customer*>&);  // keep it a pointer because it is an array

/*!
 * Using, the number that is passed in, this method adds either a new food or a new drink (whichever selected by user) to the customer's inventory
 * This method should set the cost of each item, its name, and its point worth, then add that item to the customer's order using addItemToOrder
 \param optionSelected; an integer representing the user's choice of menu item passed in from placeOrder
 \param customer; a pointer to the customer that we are adding the menu item to
*/
MenuItem& addItemToOrder(int);

/*!
 * Used in main after an order is complete to output the amount of money the system owes the customer
 * If the user's cost is more than $0, this method should prompt the user to enter they amount of money they're paying with
 * If the user does not have enough money to cover the cost of the purchase, it should output Insufficient Funds, Trying Again and loop until the user gives a large enough value to cover the cost
 * If the user has enough money, this method should output the change provided to the user
 \param customer; a pointer to the customer that needs a change calculation; provided by main
*/
void calculateChange(const Customer&);

/*!
 * This method uses the passed in userOption integer to determine which food is being redeemed under the loyalty program
 * For entries 1-4, the method should update the food name that was passed in as a string, and return the number of points that that item costs
 * entry of 0 should exit the method without setting anything
 \param foodName; a pointer the string that is used in useLoyalty to check if the user has actually added that item to the cart
 \param userOption; an int passed in from useLoyalty indicating the user's choice from the loyalty menu
 \return an integer number of points
*/
int getNumberOfPointsToRedeem(string&, int);


/*!
 * If the user chooses to use their loyalty points on their order, this method is called
 * This method should display the point redemption menu and prompt for the user's choice
 * The choice should be stored and passed to getNumberOfPointsToRedeem
 * Each item from the customer should be iterated through, and each item name should be checked to see if it matches the foodName that was returned from getNumberOfPointsToRedeem
 * If the item exists in the customer's order and the customer has enough points to cover it, the items number of points should be subtracted from the user's available points
 * Then the total cost of the customer's order should be used to calculate the number of points the order is going to be worth, which is equal to the integer value of the cost
 * That value should be added to the customer's available points, and then the cost of the item that the customer chose should be set to 0
 * Then the number of available points should be updated for that customer
 * Otherwise, if the customer does not have enough points, insufficient number of points should be output
 * If the item that the user chose as there loyalty reward does not exist in the customer's inventory, output sorry you didn't order that and set the userOption so that it will loop again
 * These steps should be repeated if the user enters an invalid number
 \param customer; a pointer to the customer using points
 \param numCustomers; the integer number of customers
 \param availablePts; the points available  for that customer, passed in from main
*/
void useLoyalty(Customer&, int);

/*! 
 * Main function; the entry point into the program.
 * After instantiating an array of customers, main should loop infinitely
 * If you've written this part correctly, the only way to stop the program will be to ctrl + c
 * This will emulate persistent code that you might see on a self-checkout register at McDonald's or the grocery store
 * Once you're looping, use getLoyaltyDatabase to read from the loyalty.txt file and get the number of customer's returned
 * Then it calls runLoyaltyProgram, and stores the customer index
 * If -1 was returned by that method, then create a new customer and insert it at the end of the customer array. DO NOT update the number of customers, because this will just be an unofficial customer stored in an easy way
 * Set the new customer's number of item to zero, and then place the customer's order
 * If the customer is a loyalty member, use the pointSystemPrompt to ask if they would like to use their loyalty points. 
 * If they would like to use their points, then call useLoyalty. Display the customer's order and calculate their change
 * If the do not want to use their points update the customer's number of points by adding the integer cast value from calculateCost to the customer's points
 * Calculate the customer's change and output have a nice day
 * If the user is not a loyalty member, then you should display the order, calculate the change, and output the have a nice day message. Finally, set that place holder customer in the array's number of item to 0
 * After change has been calculated, call overwriteLoyaltyDatabase to add new customers
*/
void promptFoodAddOns(Food&);
void selectIngredient(Food&); 
void promptDrinkExtras(Drink&);