#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../bin/ParkingLot.cpp"
using namespace std;

TEST(testAddCar, whenLotEmpty) {
    ParkingLot P(6);
    ASSERT_EQ(P.addCar("KA-01-HH-1234", "White"), 1);
    cout << "Unit Test Successful for addCar function, when parking lot was empty!\n";
}

TEST(testAddCar, whenLotFull) {
    ParkingLot P(3);
    P.addCar("KA-01-HH-1234", "White");
    P.addCar("KA-01-HH-9999", "White");
    P.addCar("KA-01-BB-0001", "Black");
    ASSERT_EQ(P.addCar("KA-01-HH-7777", "Red"), -1);
    cout << "Unit Test Successful for addCar function, when parking lot was full!\n";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
