#include "gtest/gtest.h"
#include "../../food/food.h"
#include "../../menuItem/menuItem.h"

TEST(foodTests, checkFood) {
    
    Food meatyMeatManMeal;
    meatyMeatManMeal.addIngredient("White Bread");
    meatyMeatManMeal.addIngredient("Mustard");
    meatyMeatManMeal.addIngredient("Swiss Cheese");
    meatyMeatManMeal.addIngredient("Ranch Dressing");

    EXPECT_NEAR(4, meatyMeatManMeal.getNumberIngredients(), .1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}