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



ParkingLot::ParkingLot(int n) {
    numberOfCarsAllowed = n;
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
        car.slotAllocated = emptySlot;
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

int getNumberOfSlotsFromInput(string input) {
    int n = stoi(input.substr(19));
    return n;
}

vector<string> getKeyWordsFromInput(string input) {
    vector<string> result;
    string temp;
    stringstream ss(input);
    while(getline(ss, temp, ' ')) {
        result.push_back(temp);
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Stores individual lines of the Input 
    string input;
    //Stores instruction to be performed for the given line
    string instruction;

    //Input Very First line of ParkingLot info
    getline(cin, input);
    
    //Get number of Slots to be created in Parking Lot
    int numberOfSlots = getNumberOfSlotsFromInput(input);

    //Create Object of ParkingLot Class
    ParkingLot P(numberOfSlots);

    //Success message after lot is created
    cout << "Created a parking lot with " << numberOfSlots << " slots" << endl;

    do {
        //Read operations line by line
        getline(cin, input);

        //If Empty Line as Input, stop further processing 
        if(input.empty()) {
            break;
        }

        vector<string> keyWords = getKeyWordsFromInput(input);
        //Get instruction to be performed
        instruction = keyWords[0];

        if(instruction.compare("park") == 0) {
            int slotNumber = P.addCar(keyWords[1], keyWords[2]);
            
            //If Parking Lot is full
            if(slotNumber == -1) {
                cout << "Sorry, parking lot is full" << endl;
            } else {
                cout << "Allocated slot number: " << slotNumber << endl;
            }
        } else if(instruction.compare("status") == 0) {
            P.printStatus();
        } else if(instruction.compare("leave") == 0) {
            int slotNumber = stoi(keyWords[1]);
            P.removeCar(slotNumber);
            cout << "Slot number " << slotNumber << " is free" << endl;
        } else if(instruction.compare("registration_numbers_for_cars_with_colour") == 0) {
            //Action
        } else if(instruction.compare("slot_numbers_for_cars_with_colour") == 0) {
            //Action
        } else if(instruction.compare("slot_number_for_registration_number") == 0) {

        } else if(instruction.compare("exit") == 0) {
            break;
        } else {
            cout << "Sorry Your Action Cannot Be Identified!!!" << endl;
        }
    } while(1);


    return 0;
}