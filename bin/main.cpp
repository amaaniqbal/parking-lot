//This file contains main program which uses
//classes declared in a custom header file 
//for performing operations.

#include<bits/stdc++.h>
#include "ParkingLot.h"
using namespace std;

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

    //Read operations line by line
    while(getline(cin, input)) {
        
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

            string color = keyWords[1];
            vector<string> regNumbers = P.getRegistrationNumbersByColor(color);
            for(int i=0; i<regNumbers.size(); i++) {
                cout << regNumbers[i];
                if(i != regNumbers.size()-1)
                    cout << ", ";
            } 
            cout << endl;

        } else if(instruction.compare("slot_numbers_for_cars_with_colour") == 0) {
            
            string color = keyWords[1];
            vector<int> slotNumbers = P.getSlotNumbersByColor(color);
            for(int i=0; i<slotNumbers.size(); i++) {
                cout << slotNumbers[i];
                if(i != slotNumbers.size()-1)
                    cout << ", ";
            } 
            cout << endl;

        } else if(instruction.compare("slot_number_for_registration_number") == 0) {

            string regNumber = keyWords[1];
            int slotNumber = P.getSlotNumberByRegistrationNumber(regNumber);
            if(slotNumber == -1) 
                cout << "Not found" << endl;
            else
                cout << slotNumber << endl;

        } else if(instruction.compare("exit") == 0) {
            break;
        } else {
            cout << "Sorry Your Action Cannot Be Identified!!!" << endl;
        }
    }

    return 0;
}