#include "gtest/gtest.h"
#include "../../drink/drink.h"
#include "../../menuItem/menuItem.h"

TEST(drinkTests, checkDrink) {
    
    Drink water;
    water.setSize(20);
    water.setNeedsIce(true);
    water.setNeedsStraw(false);
    water.calculateMenuItemCost();

    EXPECT_NEAR(3.50, water.getCost(), .1);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}