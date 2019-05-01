#include<bits/stdc++.h>
using namespace std;

//Car Structure stores Car info of Cars which are parked
struct Car {
    int slotAllocated;
    string registrationNumber;
    string color;
};

class ParkingLot {
    int numberOfCarsAllowed;
    int numberOfCarsParked; 

    //Contains a mappping from allocated slots to the Car info of the car parked in that slot
    unordered_map<int, Car> slotInfo;

public :
    ParkingLot(int n);
    vector<string> getRegistrationNumbersByColor(string);
    int getSlotNumberByRegistrationNumber(string);
    vector<int> getSlotNumbersByColor(string);
    //Helper Functions Here
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Input and Output goes here

    return 0;
}