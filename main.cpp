#include<bits/stdc++.h>
using namespace std;

//Car Structure stores Car info of Cars which are parked
struct Car {
    int slotAllocated;
    string registrationNumber;
    string color;
};

//This Class Stores all the information about the Parking Lot
class ParkingLot {
    int numberOfCarsAllowed;
    int numberOfCarsParked; 

    //Contains a mappping from allocated slots to the Car info of the car parked in that slot
    unordered_map<int, Car> slotInfo;

public :
    ParkingLot(int n);
    vector<string> getRegistrationNumbersByColor(string color);
    int getSlotNumberByRegistrationNumber(string registrationNumber);
    vector<int> getSlotNumbersByColor(string color);
    //Helper Functions Here
    int getNearestEmptySlot();
    void addCar(string registrationNumber, string color);
    void removeCar(int slot);
};

int getNumberOfSlotsFromInput(string input) {
    int n = stoi(input.substr(19));
    return n;
}

vector<string> getKeyWordsFromInput(string input) {
    vector<string> result;
    string temp;
    while(getline(input, temp, ' ')) {
        result.push_back(temp);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Stores individual lines of the Input 
    string input;
    
    getline(cin, input);
    int numberOfSlots = getNumberOfSlotsFromInput(input);

    //Create Object of ParkingLot Class
    ParkingLot P(numberOfSlots);

    do {
        getline(cin, input);
        vector<string> keyWords = getKeyWordsFromInput(input);
        //Get instruction to be performed
        string instruction = keyWords[0];

        if(instruction.compare("park") == 0) {
            //Action
        } else if(instruction.compare("status") == 0) {
            //Action
        } else if(instruction.compare("leave") == 0) {
            //Action
        } else if(instruction.compare("registration_numbers_for_cars_with_colour") == 0) {
            //Action
        } else if(instruction.compare("slot_numbers_for_cars_with_colour") == 0) {
            //Action
        } else if(instruction.compare("slot_number_for_registration_number") == 0) {

        } else if(instruction.compare("exit") == 0) {
            break;
        } else {
            cout << "\nSorry Your Action Cannot Be Identified!!!\n";
        }
    } while(instruction[0] != '\n');


    return 0;
}