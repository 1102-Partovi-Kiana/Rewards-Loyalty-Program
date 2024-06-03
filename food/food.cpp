//Author: Kiana Partovi 
//Date: 04/16/22
//Purpose: This is the implementation for the food class. 

#include "./food.h"
/// @cond
Food::Food(){
    numberIngredients = 0;
    //ingredients = new string[MAX_NUMBER_INGREDIENTS];
}
Food::Food(const string* ing, const int numIngredients, string name, int points, float cost): MenuItem(name, points, cost){
    //ingredients = new string[MAX_NUMBER_INGREDIENTS];
    for(int i = 0; i < numIngredients; i++){
        ingredients.getArray()[i] = ing[i];
        // ingredients[i] = ing[i];
    }
}
Food::Food(Food& rhs){
   // ingredients = new string[MAX_NUMBER_INGREDIENTS];
    for(int i = 0; i < rhs.numberIngredients; i++) {
        ingredients.getArray()[i] = rhs.ingredients.getArray()[i];
        //ingredients[i] = rhs.ingredients[i];
    }
}

/* Food::~Food() {
    delete [] ingredients;
    delete [] availableExtras;
} */

dynamicArray<string>& Food::getIngredients() {
    return ingredients;
}
void Food::addIngredient(const string ingredient){
    // string *temp = new string[numberIngredients];
    // for (int i = 0; i < numberIngredients; i++) {
    //     temp[i] = ingredients.getArray()[i];
    // }
    // ingredients = new string[numberIngredients + 1];
    // for (int i = 0; i < numberIngredients; i++) {
    //     ingredients.getArray()[i] = temp[i];
    // }
    // delete [] temp;
    ingredients.addItemToArray(ingredient);
    
    //ingredients.getArray()[numberIngredients] = ingredient;
   // numberIngredients++; MIGHT NEED THIS BACK
}

int Food::getNumberIngredients() const{
    return numberIngredients;
}


ostream& Food::displayItemInformation(ostream& stream) const {
    MenuItem::displayItemInformation(stream);
    stream << "INGREDIENTS: ";
    for (int i = 0; i < ingredients.getCurrentNumItemsInArr(); i++) {
        stream << ingredients.returnsElementAtSpecifiedIndex(i);
       // cout << ingredients.getArray()[i];
        if (i < ingredients.getCurrentNumItemsInArr() - 1) {
            stream << ", ";
        }
    }
    stream << endl;
    return stream;
}

dynamicArray<string>& Food::getAvailableExtras() {
    return availableExtras;
}

int Food::getNumExtras(){
    return numAvailableExtras;
}

void Food::setAvailableExtras() {


    //with any item available in the other 2 food items that is not normally in that food item. 
    //So, for example, if the user wants a Smoked Meat Sandwich, the available extras are BBQ Sauce, Toast, Potatoes, 
    //Ranch Dressing, and Broccoli. 
    string tempArrayMeal[4] = {"White Bread", "Mustard", "Swiss Cheese", "Ranch Dressing"};
    string tempArrayTots[7] = {"Smoked Meat", "White Bread", "Mustard", "Swiss Cheese", "Toast", "BBQ Sauce", "Broccoli"};
    string tempArraySandwich[5] = {"Toast", "Potatoes", "BBQ Sauce", "Broccoli", "Ranch Dressing"};
    
    string itemName = getItemName();
    if (itemName == "Smoked Meat Sandwich") {
        //availableExtras.setCurrentNumItemsInArr(5);
        // setNumAvailableExtras(5);
        numAvailableExtras = 5;
        //availableExtras.setCurrentNumItemsInArr(numAvailableExtras);
        for(int i = 0; i < numAvailableExtras; i++) 
        {
            availableExtras.addItemToArray(tempArraySandwich[i]);
            //cout << availableExtras.returnsElementAtSpecifiedIndex(i);
            //availableExtras.getArray()[i] = tempArraySandwich[i];
        }
    } else if (itemName == "Meaty Meat Man Meal") {
        numAvailableExtras = 4;
        //availableExtras.setCurrentNumItemsInArr(numAvailableExtras);
        for (int i = 0; i < numAvailableExtras; i++) 
        {
            availableExtras.addItemToArray(tempArrayMeal[i]);
            //availableExtras.getArray()[i] = tempArrayMeal[i];
        }
    } else if (itemName == "Tater Tots") {
        numAvailableExtras = 7;
        //availableExtras.setCurrentNumItemsInArr(numAvailableExtras);
        for (int i = 0; i < numAvailableExtras; i++) {
            availableExtras.addItemToArray(tempArrayTots[i]);
            //availableExtras.getArray()[i] = tempArrayTots[i];
        }
    } 
}

void Food::calculateMenuItemCost() {
    float money = 0.00;
    float cost = 0.00;
   // cost = (float)getNumberIngredients() * 0.50;  // c style cast
   //string item = getItemName();
    if (getItemName() == "Smoked Meat Sandwich") {
        float h = 0.00;
        h = ingredients.getCurrentNumItemsInArr() - 5;
        money = h * 0.50;
        cost = money + getCost();
        setCost(cost);
    } else if (getItemName() == "Meaty Meat Man Meal") {
        float g = 0.00;
        g = ingredients.getCurrentNumItemsInArr() - 4;
        money = g * 0.50;
        cost = money + getCost();
        setCost(cost);
    } else if (getItemName() == "Tater Tots") {
        setCost(3.99);
        float x = 0.00;
        x = ingredients.getCurrentNumItemsInArr() - 7;
        money = x * 0.50;
        cost = money + getCost();
        setCost(cost);
    }
}

void Food::setNumAvailableExtras (int numExtras) {
    availableExtras.setCurrentNumItemsInArr(numExtras);
    //numAvailableExtras = numExtras;
}

/// @endcond