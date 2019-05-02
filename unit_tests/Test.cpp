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

TEST(testGetNearestEmptySlot, whenLotEmpty) {
    ParkingLot P(6);
    ASSERT_EQ(P.getNearestEmptySlot(), 1);
    cout << "Unit Test Successful for getNearestEmptySlot function, when parking lot was empty!\n";
}

TEST(testGetNearestEmptySlot, whenLotFull) {
    ParkingLot P(3);
    P.addCar("KA-01-HH-1234", "White");
    P.addCar("KA-01-HH-9999", "White");
    P.addCar("KA-01-BB-0001", "Black");
    ASSERT_EQ(P.getNearestEmptySlot(), -1);
    cout << "Unit Test Successful for getNearestEmptySlot function, when parking lot was full!\n";
}

TEST(testGetSlotNumberByRegistrationNumber, whenCarPresent) {
    ParkingLot P(3);
    P.addCar("KA-01-HH-1234", "White");
    P.addCar("KA-01-HH-9999", "White");
    P.addCar("KA-01-BB-0001", "Black");
    ASSERT_EQ(P.getSlotNumberByRegistrationNumber("KA-01-HH-9999"), 2);
    cout << "Unit Test Successful for getSlotNumberByRegistrationNumber function, when searched car was present!\n";
}

TEST(testGetSlotNumberByRegistrationNumber, whenCarAbsent) {
    ParkingLot P(3);
    P.addCar("KA-01-HH-1234", "White");
    P.addCar("KA-01-HH-9999", "White");
    P.addCar("KA-01-BB-0001", "Black");
    ASSERT_EQ(P.getSlotNumberByRegistrationNumber("KA-01-HH-9900"), -1);
    cout << "Unit Test Successful for getSlotNumberByRegistrationNumber function, when searched car was absent!\n";
}

TEST(testGetRegistrationNumbersByColor, whenColorPresent) {
    ParkingLot P(3);
    P.addCar("KA-01-HH-1234", "White");
    P.addCar("KA-01-HH-9999", "White");
    P.addCar("KA-01-BB-0001", "Black");
    
    //Get Registration Numbers
    vector<string> regNumber = P.getRegistrationNumbersByColor("White");
    ASSERT_EQ(regNumber[0], "KA-01-HH-1234");
    ASSERT_EQ(regNumber[1], "KA-01-HH-9999");
    cout << "Unit Test Successful for getRegistrationNumbersByColor function, when searched color was present!\n";
}

TEST(testGetRegistrationNumbersByColor, whenColorAbsent) {
    ParkingLot P(3);
    P.addCar("KA-01-HH-1234", "White");
    P.addCar("KA-01-HH-9999", "White");
    P.addCar("KA-01-BB-0001", "Black");
    
    //Get Registration Numbers
    vector<string> regNumber = P.getRegistrationNumbersByColor("Red");
    ASSERT_EQ(regNumber.size(), 0);
    cout << "Unit Test Successful for getRegistrationNumbersByColor function, when searched color was absent!\n";
}

int main(int argc, char **argv) {
    testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}
