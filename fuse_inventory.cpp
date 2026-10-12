    /*
    * Course: COEN 2210 - Introduction to Programming
    * Name: [Ashley Martinez]
    * Lab: 8 - Functions
    * Description: [This program manages the inventory of a fuse cabinet, allowing the user to input the number of spare fuses and whether a fuse was used, updating the inventory accordingly.]
    * Due Date: [10/10/2026]
    */

    #include <iostream>                                      // Provides cin, cout, and endl
    using namespace std;                                     // Allows standard-library names without the std:: prefix

    void displayCabinetHeading();                          // TODO: Declare prototype for the heading function
    void reportFuseUsage(char usedFuse);                     // TODO: Declare prototype for the usage reporting function
    void updateInventory(int &fuseCount);                    // TODO: Declare prototype for the inventory update function

    int main() {                                             // Starts the program
        int fuseCount;                                       // Stores the official number of spare fuses
        char usedFuse;                                       // Stores the technician decision

        displayCabinetHeading();
        cout << "Enter the number of spare fuses: ";
        cin >> fuseCount;
        cout << "Did the technician use a fuse? (Y/N): ";
        cin >> usedFuse;

        if (usedFuse == 'Y' || usedFuse == 'y') {          
            updateInventory(fuseCount);
            reportFuseUsage(usedFuse);
        } else if (usedFuse == 'N' || usedFuse == 'n') {   
            reportFuseUsage(usedFuse);
        } else {                                            
            reportFuseUsage(usedFuse);
        }

        cout << "Final number of spare fuses: " << fuseCount << endl;

        return 0;                                            // Ends the program successfully
    }                                                        // Ends the main function

    void displayCabinetHeading() {
        cout << "      Fuse Cabinet Inventory" << endl;
    }

    void reportFuseUsage(char usedFuse) {
        if (usedFuse == 'Y' || usedFuse == 'y') {
            cout << "A fuse was used." << endl;
        } else {
            cout << "No fuse was used." << endl;
        }
    }

    void updateInventory(int &fuseCount) {
        if (fuseCount > 0) {
            --fuseCount;
        }
    }

    /*
    Test Cases:
    1. fuseCount = 5, usedFuse = 'Y' -> Final count = 4
    2. fuseCount = 5, usedFuse = 'N' -> Final count = 5
    3. fuseCount = 0, usedFuse = 'Y' -> Final count = 0
    4. fuseCount = 1, usedFuse = 'y' -> Final count = 0

    Analysis:
    Only the updateInventory function needs the reference parameter (&) because it must change the original value of fuseCount in main.
    If fuseCount were passed by value, the function would only change a copy and the original value would remain the same. The other functions only read information or print output, so they do not need to modify the original variable.
    */