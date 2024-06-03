//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is a cpp file for the implementation of the methods of the customer class created in the customer header file. 

#include "./customer.h"
/// @cond
Customer::Customer(){
    customerFirst = "Jane";
    customerLast = "Doe";
    loyaltyNumber = 1111111;
    numberLoyaltyPoints = 0;
    //numItemsInOrder = 0;
    orderCost = 0.00;
    //currentOrder = new MenuItem*[STARTSIZEORDER]; // added this 
    //currentOrder[0] = MenuItem();
}
Customer::Customer(const string first,const string last, const long int id, const long int numPts){
    customerFirst = first;
    customerLast = last;
    loyaltyNumber = id;
    numberLoyaltyPoints = numPts;
    //numItemsInOrder = 0;
    //currentOrder = new MenuItem*[STARTSIZEORDER]; // added this
   // currentOrder[0] = MenuItem();
}
Customer::Customer(const Customer& rhs){
    customerFirst = rhs.customerFirst;
    customerLast = rhs.customerLast;
    loyaltyNumber = rhs.loyaltyNumber;
    numberLoyaltyPoints = rhs.numberLoyaltyPoints;
    //numItemsInOrder = rhs.numItemsInOrder;
    //currentOrder = new MenuItem*[STARTSIZEORDER]; 
    for(int i = 0; i < rhs.currentOrder.getCurrentNumItemsInArr(); i++){
        *currentOrder.returnsElementAtSpecifiedIndex(i) = *rhs.currentOrder.returnsElementAtSpecifiedIndex(i);
    }
}

/*Customer::~Customer() {
    // delete each pointer at each index
    // delete pointer to array
    for (int i = 0; i < STARTSIZEORDER; i++) {
        delete currentOrder[i];
    } 
    delete [] currentOrder; // delete the pointer that is a pointer to everything
} */

string Customer::getCustomerFirst() const {
    return customerFirst;
}
void Customer::setCustomerFirst(const string name) {
    customerFirst = name;
}

string Customer::getCustomerLast() const{
    return customerLast;
}
void Customer::setCustomerLast(const string name) {
    customerLast = name;
}

long int Customer::getLoyaltyNumber() const{
    return loyaltyNumber;
}
void Customer::setLoyaltyNumber(const long int id) {
    loyaltyNumber = id;
}   

long int Customer::getNumberLoyaltyPoints() const {
    return numberLoyaltyPoints;
}
void Customer::setNumberLoyaltyPoints(const long int numPts) const {
    numberLoyaltyPoints = numPts;
}

dynamicArray<MenuItem*>& Customer::getCurrentOrder() {
    return currentOrder;
}
void Customer::addItemToOrder(const MenuItem& newItem) {
    // const Customer& currentCustomer = *(customers.returnsElementAtSpecifiedIndex(customerIndex));
    // dynamicArray<MenuItem*> order = placeOrder(currentCustomer);
    // cout << newItem.getItemName() << endl;
    const MenuItem* ptr = &newItem;
    MenuItem* refPtr = const_cast<MenuItem*>(ptr);
    // currentOrder.addItemToArray(&newItem);
    currentOrder.addItemToArray(refPtr);
    // numItemsInOrder++;
    // cout << currentOrder.returnsElementAtSpecifiedIndex(currentOrder.getCurrentNumItemsInArr() - 1)->getItemName() << endl;
}

/* int Customer::getNumItemsInOrder() const{
    numItemsInOrder = currentOrder.getCurrentNumItemsInArr();
    return numItemsInOrder;
} */

float Customer::calculateCost() const {
    float customerTotal = 0;
    float currentTaxRate = 1.0827;
    const float temp = 0.00;
    for(int i = 0; i < currentOrder.getCurrentNumItemsInArr(); i++){
        // currentOrder.returnsElementAtSpecifiedIndex(i)->calculateMenuItemCost();
        customerTotal += currentOrder.returnsElementAtSpecifiedIndex(i)->operator+(temp);
        //customerTotal += currentOrder.returnsElementAtSpecifiedIndex(i)->getCost();
    }
    //cout << customerTotal << endl;
    customerTotal *= currentTaxRate;
    if (counter == 0) {
        orderCost = customerTotal;
        counter++;
    }
    return customerTotal;
}

/* void Customer::displayOrder() const{
    cout <<endl << "=====Your Order=====" << endl;
    for(int i = 0; i < currentOrder.getCurrentNumItemsInArr(); i++){
        cout << currentOrder.returnsElementAtSpecifiedIndex(i)->getItemName() << " " << "$" << currentOrder.returnsElementAtSpecifiedIndex(i)->getCost() << endl;
        currentOrder.returnsElementAtSpecifiedIndex(i)->displayItemInformation();
        //cout << endl;
    }
    calculateCost();
    cout << "Your Total Today Is: $" << std::fixed << setprecision(2) << orderCost << endl << endl;

} */

void Customer::displayCustomerInformation() const {
    cout <<endl << "Welcome " << getCustomerFirst() <<" " << getCustomerLast() << "!" << endl;
    cout << "You have " << getNumberLoyaltyPoints() << " Loyalty Points." << endl;
}

/* void Customer::setNumItemsInOrder(int numItem) const{
    numItemsInOrder = numItem;
} */

void Customer::clearOrder() {
    currentOrder.doesAlotOfStuff();
}

void Customer::setOrderCost(float newCost) {
    orderCost = newCost;
}

float Customer::getOrderCost() const {
    return orderCost;
}

ostream& operator << (ostream& o, const Customer& cus) {
    o << endl << "=====Your Order=====" << endl;
    for(int i = 0; i < cus.currentOrder.getCurrentNumItemsInArr(); i++){
        // cout << cus.currentOrder.returnsElementAtSpecifiedIndex(i)->getItemName() << " " << "$" << cus.currentOrder.returnsElementAtSpecifiedIndex(i)->getCost() << endl;
        
        o << *(cus.currentOrder.returnsElementAtSpecifiedIndex(i)) << endl;
        // o << cus.currentOrder.returnsElementAtSpecifiedIndex(i)->displayItemInformation();
        //cout << endl;
    }
    cus.calculateCost();
    o << "Your Total Today Is: $" << std::fixed << setprecision(2) << cus.orderCost << endl << endl;
    return o;
}
/// @endcond