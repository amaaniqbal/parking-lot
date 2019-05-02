//This file contains helper member functions for
//ParkingLot class

#include <bits/stdc++.h>
#include "ParkingLot.h"

ParkingLot::ParkingLot(int n) {
    numberOfCarsAllowed = n;
}

vector<string> ParkingLot::getRegistrationNumbersByColor(string color) {
    vector<string> result;
    for(auto it = slotInfo.begin(); it != slotInfo.end(); it++) {
        if((it->second).color.compare(color) == 0)
            result.push_back((it->second).registrationNumber);
    }
    return result;
}

int ParkingLot::getSlotNumberByRegistrationNumber(string regNumber) {
    for(auto it = slotInfo.begin(); it != slotInfo.end(); it++) {
        if((it->second).registrationNumber.compare(regNumber) == 0)
            return it->first;
    }
    //If no car with given Registration number is found
    return -1;
}

vector<int> ParkingLot::getSlotNumbersByColor(string color) {
    vector<int> result;
    for(auto it = slotInfo.begin(); it != slotInfo.end(); it++) {
        if((it->second).color.compare(color) == 0)
            result.push_back(it->first);
    }
    return result;
}

int ParkingLot::getNearestEmptySlot() {
    //If parking lot empty
    if(slotInfo.size() == 0) {
        return 1;

    //If parking lot full
    } else if(slotInfo.size() == numberOfCarsAllowed) {
        return -1;
    } else {
        int ptr = 1;
        for(auto it = slotInfo.begin(); it != slotInfo.end(); it++) {
            //Is ptr slot empty
            if(it->first != ptr) {
                return ptr;
            }
            ptr++;
        }
        //If all the slots are filled in order
        return ptr;
    }
}

int ParkingLot::addCar(string regNumber, string color) {
    int emptySlot = getNearestEmptySlot();
    //If no slot empty
    if(emptySlot == -1) {
        return -1;
    } else {
        Car car;
        car.registrationNumber = regNumber;
        car.color = color;
        
        //Insert the corresponding data in slotInfo
        slotInfo[emptySlot] = car;

        return emptySlot;
    }
}

void ParkingLot::printStatus() {
    cout << left << setw(10) << "Slot No." << left << setw(20) << "Registration No" << setw(20) << "Colour" << endl;
    for(auto it = slotInfo.begin(); it != slotInfo.end(); it++) 
        cout << left << setw(10) << it->first << left << setw(20) << (it->second).registrationNumber << setw(20) << (it->second).color << endl;
}

void ParkingLot::removeCar(int slotNumber) {
    slotInfo.erase(slotNumber);
}