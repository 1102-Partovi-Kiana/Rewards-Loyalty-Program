#include "./helperFunctions.h"

void calculateChange(const Customer& currentCustomer){
    float customerMoney = 0;
    do{
        
        currentCustomer.calculateCost();
        if(currentCustomer.getOrderCost() != 0){
            cout << endl << endl << "Please enter the amount you'd like to pay with: $";
            cin >> customerMoney;
            if(customerMoney < currentCustomer.getOrderCost()){
                cout << "Insufficient Funds, Trying Again..." << endl;
            }
            else{
                
                cout << "Your change today is: $" << std::fixed <<setprecision(2) <<customerMoney - currentCustomer.getOrderCost() << endl;
            }
        }
    }while(customerMoney < currentCustomer.getOrderCost());
}

template <typename T>
T getUserChoice() {
    T tempvar;
    cin >> tempvar;
    return tempvar;
}

Customer* createCustomer(){
    displayLoyaltyInformationPrompt();
    int loyaltyNum = getUserChoice<int>(); //getUserIntChoice();
    string first = getUserChoice<string>(); //getUserStringEntry();
    string last = getUserChoice<string>(); //getUserStringEntry();

    Customer* newMember = new Customer;
    //cout << first << " " << last << " " << endl;
    newMember->setCustomerFirst(first);
    newMember->setCustomerLast(last);
    newMember->setLoyaltyNumber(loyaltyNum);
    newMember->setNumberLoyaltyPoints(50);
    return newMember;
}

void displayLoyaltyInformationPrompt(){
    cout << "Enrolling in the Meat Man Mob Loyalty Program is simple!" << endl;
    cout << "Just enter your 7 digit phone number without any dashes and your first and last name!" << endl;
    cout << "For example: 1111111 Pete Wentz" << endl << endl;
}

void displayPointRedemptionMenu(){
    cout << "1.) Sandwich, 450 pts" << endl;
    cout << "2.) 32 oz. Drink, 50 pts" << endl;
    cout << "3.) Meat Man Meal, 500 pts" << endl;
    cout << "4.) Small Tater Tot, 75 pts" << endl;
}

void displayMemberJoin(){
    cout << endl << endl<<"Don't have a loyalty number?" << endl;
    cout << "Join today and earn a free large drink!" << endl;
    cout << "Being a member of the Meat Man Mob Loyalty Program provides the following benefits: " << endl;
    displayPointRedemptionMenu();
    cout << endl<< "Would you like to join the Meat Man Mob Loyalty Program?(y/n) ";
}

int runLoyaltyProgram(dynamicArray<Customer*>& customers){
    int numCustomers = customers.getCurrentNumItemsInArr();
    cout <<endl << endl<< "Welcome to Meaty Meat Man's Market!" << endl;
    cout << endl << "Are you a member of the Meat Man Mob Loyalty Program? (y/n/e to exit):";
    char loyal = getUserChoice<char>(); //getUserCharChoice(); 
    char userChoice = '.';
    if(loyal == 'e' || loyal == 'E'){
        return -2;
    }

    do{
        if (loyal == 'y' || loyal == 'Y'){
            cout << endl<<"Please enter your loyalty number: ";
            int loyaltyNumber = getUserChoice<int>(); //getUserIntChoice();
            for(int i = 0; i < numCustomers; i++){
                if(customers.returnsElementAtSpecifiedIndex(i)->getLoyaltyNumber() == loyaltyNumber){
                    customers.returnsElementAtSpecifiedIndex(i)->displayCustomerInformation();
                    return i;
                }
            }
            loyal = 'N';
        }
        if(loyal == 'N' || loyal == 'n'){
            char join;
            do{
                displayMemberJoin();
                join = getUserChoice<char>(); //getUserCharChoice();
            }while(join != 'y' && join != 'Y' && join != 'n' && join != 'N');
            if(join != 'y' && join != 'Y'){        
                return -1;
            }
            if(join == 'Y' || join == 'y'){
                Customer *newMember = createCustomer();  // NEED TO DYNAMICALLY ALLOCATE THIS
                customers.addItemToArray(newMember);
                numCustomers += 1;
                newMember->displayCustomerInformation();
                return (numCustomers)-1;
            }

            
        }
    }while(loyal != 'y' || loyal != 'Y' || loyal != 'n' || loyal != 'N');

    return -1;
}

void getLoyaltyDatabase(dynamicArray<Customer*>& loyaltyCustomers){
    string firstName, lastName;
    long int loyaltyNumber, numberPoints;
    int numCustomers = 0;
    string space = " ";
    ifstream loyaltyMemberStream("loyalty.txt"); 
    if (loyaltyMemberStream.is_open() ) { 
        while(loyaltyMemberStream.good()){
            loyaltyMemberStream >> loyaltyNumber >> firstName >> lastName >> numberPoints;
            Customer* newCustomer = new Customer(firstName, lastName, loyaltyNumber, numberPoints);
            //cout << newCustomer->getCustomerFirst() << endl;
            loyaltyCustomers.addItemToArray(newCustomer);
            //cout << loyaltyCustomers.returnsElementAtSpecifiedIndex(loyaltyCustomers.getCurrentNumItemsInArr()-1)->getCustomerFirst() << endl;
        }
    }
    //return loyaltyCustomers.getCurrentNumItemsInArr();  // changed this from return numCustomers to return loyaltyCustomers.getCurrentNumItemsInArr()
}

void overwriteLoyaltyDatabase(dynamicArray<Customer*>& customers) {
    int numCustomers = customers.getCurrentNumItemsInArr();
    ofstream loyaltyMemberStream("loyalty.txt"); 
    //cout << customers.getCurrentNumItemsInArr() << endl;
    for(int i = 0; i < customers.getCurrentNumItemsInArr(); i++){
        // cout << customers.returnsElementAtSpecifiedIndex(i)->getLoyaltyNumber() << endl;
        // cout << customers.returnsElementAtSpecifiedIndex(i)->getCustomerFirst() << endl;
        // cout << customers.returnsElementAtSpecifiedIndex(i)->getCustomerLast() << endl;
        // cout << customers.returnsElementAtSpecifiedIndex(i)->getNumberLoyaltyPoints() << endl;
        
        loyaltyMemberStream << customers.returnsElementAtSpecifiedIndex(i)->getLoyaltyNumber() << " " << customers.returnsElementAtSpecifiedIndex(i)->getCustomerFirst() << " " << customers.returnsElementAtSpecifiedIndex(i)->getCustomerLast() << " " << customers.returnsElementAtSpecifiedIndex(i)->getNumberLoyaltyPoints();
        if(i!= numCustomers -1){
            loyaltyMemberStream << endl;
        }
    }
}

void displayMenuItems(){
    cout << endl<< "=====Meaty Meat Man's Restaurant Menu===== " << endl;
    cout << "1.) Smoked Meat Sandwich" << endl;
    cout << "2.) Meaty Meat Man Meal" << endl;
    cout << "3.) Fountain Drink" <<endl;
    cout << "4.) Tater Tots" << endl;
    cout << "0.) Finish Order" << endl;
    cout <<endl<< "Please Enter a Value [0-4]: ";
}

MenuItem& addItemToOrder(int numObject){
    Food* newFood = new Food();  // pointer to an object 
    Drink* newDrink = new Drink();
    if (numObject == 1) {       
            // newFood = new Food();  // fixed this
            newFood->setCost(12.99);
            newFood->addIngredient("Toast"); //// these are different
            newFood->addIngredient("Potatoes");
            newFood->addIngredient("BBQ Sauce");
            newFood->addIngredient("Broccoli");
            newFood->addIngredient("Ranch Dressing");
            newFood->setItemName("Smoked Meat Sandwich");
            newFood->setPointWorth(450);
            promptFoodAddOns(*newFood);
            delete newDrink;
            // currentCustomer.addItemToOrder(*newFood);  // changed it to a dot, because I am passing in the object by reference and not the pointer to an object
            return *newFood;
    } else if (numObject == 2) {  
            // newFood =  new Food(); // fixed this to dynamically allocate the local variable
            newFood->setCost(15.99);
            newFood->addIngredient("White Bread");
            newFood->addIngredient("Mustard");
            newFood->addIngredient("Swiss Cheese");
            newFood->addIngredient("Ranch Dressing");
            newFood->setItemName("Meaty Meat Man Meal");
            newFood->setPointWorth(500);
            promptFoodAddOns(*newFood);  // dereference because we need the value to pass to object
            // currentCustomer.addItemToOrder(*newFood);
            delete newDrink;
            return *newFood;
    } else if (numObject == 3) {
            // newDrink = new Drink();
            newDrink->setCost(2.99);
            newDrink->setNeedsIce(true);
            newDrink->setNeedsStraw(false);
            newDrink->setSize(16);
            newDrink->setItemName("Fountain Drink");
            newDrink->setPointWorth(50);
            promptDrinkExtras(*newDrink);
            // currentCustomer.addItemToOrder(*newDrink);
            delete newFood;
            return *newDrink;
    } else if (numObject == 4) {
            // newFood = new Food();
            newFood->setCost(3.99);
            newFood->addIngredient("Smoked Meat");
            newFood->addIngredient("White Bread");
            newFood->addIngredient("Mustard");
            newFood->addIngredient("Swiss Cheese");
            newFood->addIngredient("Toast");
            newFood->addIngredient("BBQ Sauce");
            newFood->addIngredient("Broccoli");
            newFood->setItemName("Tater Tots");
            newFood->setPointWorth(75);
            promptFoodAddOns(*newFood);
            // currentCustomer.addItemToOrder(*newFood);
            delete newDrink;
            return *newFood;
    } else if (numObject == 0) {
            delete newDrink;
            delete newFood;
            ;
    } else {
            delete newDrink;
            delete newFood;
            cout << "Invalid option entered. Please enter a value [0-4]" << endl;
     }
}

dynamicArray<MenuItem*> placeOrder(const Customer& currentCustomer){
    dynamicArray<MenuItem*> tempOrder;
    int menuItem = -1;
    do{
        displayMenuItems();
        menuItem = getUserChoice<int>(); //getUserIntChoice();
        if (menuItem == 0) {
            break;
        }
        // const MenuItem* item = &addItemToOrder(menuItem, currentCustomer);
        const MenuItem* ptr = &addItemToOrder(menuItem);
        MenuItem* refPtr = const_cast<MenuItem*>(ptr);
        tempOrder.addItemToArray(refPtr);
        //cout << tempOrder.returnsElementAtSpecifiedIndex(tempOrder.getCurrentNumItemsInArr()-1)->getItemName() << endl;
    }while(menuItem != 0);
    return tempOrder;

}

bool pointSystemPrompt(const Customer& customer){
    char useLoyalty;
    int availablePts = customer.getNumberLoyaltyPoints();
    if(availablePts >= 50){
        do{
            cout << endl << "Would you like to use any of your " <<availablePts<< " Loyalty Points (y/n)? ";
            int temp;
            cin >> useLoyalty;
        }while(useLoyalty != 'y' && useLoyalty != 'Y' && useLoyalty != 'n' && useLoyalty != 'N');
        if((useLoyalty == 'N' || useLoyalty == 'n') ){
            cout << "Cool, we'll bank those points for later!" <<endl;
            return false;
        }
        return true;
    }
    else{
        return false;
    }
}
void useLoyalty(Customer& customer, int availablePts){
    int userOption, numPts;
    string foodName; 
    do{
        displayPointRedemptionMenu();
        cout << "0.) I've changed my mind!" << endl;
        cout << endl<< "Which offer would you like to redeem? [0-4] ";


        userOption = getUserChoice<int>(); //getUserIntChoice();
        numPts = getNumberOfPointsToRedeem(foodName, userOption);


        bool found = false;


        //cout << "THIS IS THE NUMBER OF ITEMS: " << customer.getCurrentOrder().getCurrentNumItemsInArr() << endl;
        int iterations = customer.getCurrentOrder().getCurrentNumItemsInArr();
        for(int i=0; i < iterations; i++){
            if(customer.getCurrentOrder().returnsElementAtSpecifiedIndex(i)->getItemName() == foodName){
                found = true;
                if(numPts <= availablePts){
                    availablePts -= numPts;
                    int ptsToAdd = customer.calculateCost();
                    availablePts += ptsToAdd;
                    //cout << customer.getCurrentOrder().returnsElementAtSpecifiedIndex(i)->getCost() << endl;
                    customer.getCurrentOrder().returnsElementAtSpecifiedIndex(i)->setCost(0);
                    //cout << customer.getCurrentOrder().returnsElementAtSpecifiedIndex(i)->getCost() << endl;
                    customer.setNumberLoyaltyPoints(availablePts);
                    customer.counter = 0;
                }
                else{
                    cout << endl << "Insufficient number of points! Try again another time :) " << endl << endl;
                }
            }
        }
        
        if(!found){
            cout <<endl << "Sorry you didn't order that! Try again another time :)" << endl << endl;
            userOption = -1;
        }

    } while((userOption < 0 || userOption > 4));
}

int getNumberOfPointsToRedeem(string& foodName, int userOption){
    int numPts;
    switch(userOption){
        case 1:
            foodName = "Smoked Meat Sandwich";
            numPts = 450;
            break;
        case 2:
            foodName = "Fountain Drink";
            numPts = 50;
            break;
        case 3:
            foodName = "Meaty Meat Man Meal";
            numPts = 500;
            break;
        case 4:
            foodName = "Tater Tots";
            numPts = 75;
            break;
        case 0:
            break;
    }
    return numPts;
}

void promptFoodAddOns(Food& f) {
    char choice = '\0';
    while (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') { 
        cout << "Would you like to add any addtional ingredients? (y/n): ";
        cin >> choice;
        switch (choice) {
            case 'y': {
                selectIngredient(f);
                //cout << "bry" << endl;
                break;
            }
            case 'Y': {
                selectIngredient(f);
                break;
            }
        case 'n': {
            return;
            break;
        }
        case 'N': {
            return;
            break;
        }
        default: {
            break; 
        }
    }
}
            //cout << "yo" << endl;

}

void selectIngredient(Food& food) {
   
    int addThis = 0;
    int i = 0;
    cout << endl;
    cout << "AVAILABLE ADD ONS" << endl << endl;
    food.setAvailableExtras();
    for (int i = 0; i < food.getIngredients().getCurrentNumItemsInArr(); i++) {
        cout << i + 1 << ". ";
        cout << food.getIngredients().returnsElementAtSpecifiedIndex(i) << endl;
    }
    cout << food.getIngredients().getCurrentNumItemsInArr() + 1 << ". Done adding" << endl << endl;

    //done

    while (addThis != food.getAvailableExtras().getCurrentNumItemsInArr() + 1) {
        // cout << food.getIngredients().getCurrentNumItemsInArr() + 1 << endl;
        cout << "What would you like to add? ";
        cin >> addThis;
        //food->setAvailableExtras();
        //cout << "does it do this?" << endl;
        if (addThis > 0 && addThis < food.getAvailableExtras().getCurrentNumItemsInArr() + 1) {  // had to change to = so it would enter the if statement
            //cout << food->getAvailableExtras()[addThis - 1];
            // food.addIngredient(food.getAvailableExtras()[addThis - 1]);
            food.addIngredient(food.getAvailableExtras().returnsElementAtSpecifiedIndex(addThis - 1));
        }
        //cout << "hi" << endl;
    }
    food.calculateMenuItemCost();
    
}

void promptDrinkExtras(Drink& drink) {
    int size;
    char straw;
    char ice;
    cout << "What size? (16, 20, 32) oz: ";
    cin >> size;
    drink.setSize(size);
    cout << "Would you like a straw? (y/n): ";
    cin >> straw;
    if (straw == 'y') {
        drink.setNeedsStraw(true);
    } else if (straw == 'n') {
        drink.setNeedsStraw(false);
    }
    //drink->setNeedsStraw(straw);
    cout << "Would you like ice? (y/n): ";
    cin >> ice;
    if (ice == 'y') {
        drink.setNeedsIce(true);
    } else if (ice == 'n') {
        drink.setNeedsIce(false);
    }
    //drink->setNeedsIce(ice);
    cout << endl;

    drink.calculateMenuItemCost();
}