//This file contains the abstract info about ParkingLot

#include <bits/stdc++.h>
using namespace std;

//Car Structure stores Car info of Cars which are parked
struct Car {
    string registrationNumber;
    string color;
};

//This Class Stores all the information about the Parking Lot
class ParkingLot {
    int numberOfCarsAllowed;

    //Contains a sorted mappping from allocated slots to the Car info of the car parked in that slot
    map<int, Car> slotInfo;

public :
    ParkingLot(int n);
    vector<string> getRegistrationNumbersByColor(string color);
    int getSlotNumberByRegistrationNumber(string registrationNumber);
    vector<int> getSlotNumbersByColor(string color);
    //Helper Functions Here
    void printStatus();
    int getNearestEmptySlot();
    int addCar(string registrationNumber, string color);
    void removeCar(int slot);
};