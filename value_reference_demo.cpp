    /*
    * Course: COEN 2210 - Introduction to Programming
    * Name: [Ashley Martinez]
    * Lab: 8 - Functions
    * Description: [This program demonstrates the difference between value and reference parameters in C++. It shows how a function can either work with a copy of a variable or directly modify the original variable.]
    * Due Date: [10/10/2026]
    */

    #include <iostream>                                      // Provides cin, cout, and endl
    using namespace std;                                     // Allows standard-library names without the std:: prefix

    void showProjectedCount(int completedInspections);       // Declares a value-parameter function
    void recordCompletedInspection(int &completedInspections); // Declares a reference-parameter function

    int main() {                                             // Starts the program
        int completedInspections;                            // Stores the official completed-inspection count

        cout << "Enter completed inspections: ";           // Prompts for the official count
        cin >> completedInspections;                         // Reads the value stored by main

        showProjectedCount(completedInspections);            // Sends a copied count to the first function
        cout << "After projection: " << completedInspections << endl; // Shows that main kept its count
        recordCompletedInspection(completedInspections);     // Sends the original count by reference
        cout << "After recording: " << completedInspections << endl; // Shows that main now stores the update

        return 0;                                            // Ends the program successfully
    }                                                        // Ends the main function

    void showProjectedCount(int completedInspections) {      // Defines a function that changes only its local copy
        completedInspections++;                              // Adds one only to the copied parameter
        cout << "Projected count: " << completedInspections << endl; // Displays the possible next count
    }                                                        // Ends the value-parameter function

    void recordCompletedInspection(int &completedInspections) { // Defines a function that accesses the original variable
        completedInspections++;                              // Changes the official count through the reference
        cout << "Inspection recorded." << endl;             // Confirms the permanent update
    }                                                        // Ends the reference-parameter function

    /*
    Example run with input 7:
    Enter completed inspections: 7
    Projected count: 8
    After projection: 7
    Inspection recorded.
    After recording: 8

    Why the counts differ:
    showProjectedCount() uses a copy, so it changes only the local value.
    recordCompletedInspection() uses a reference, so it changes the original variable in main().
    */