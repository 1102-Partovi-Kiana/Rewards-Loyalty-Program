#include "gtest/gtest.h"
#include "../../customer/customer.h"
#include "../../drink/drink.h"
#include "../../food/food.h"

TEST(customerTests, check) {

    Customer *jeff = new Customer;
    Drink *pepsi = new Drink;
    pepsi->setCost(6.99);
    jeff->addItemToOrder(*pepsi);

    Drink *cola = new Drink;
    cola->setCost(6.99);
    jeff->addItemToOrder(*cola);


    EXPECT_NEAR(15.13, jeff->calculateCost(), .1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
