    /*
    * Course: COEN 2210 - Introduction to Programming
    * Name: [Ashley Martinez]
    * Lab: 8 - Functions
    * Description: [This program manages the registration for a workshop, allowing users to register attendees, cancel registrations, and track available seats. It demonstrates the use of reference parameters to modify the number of available seats directly.]
    * Due Date: [10/10/2026]
    */

    #include <iostream>                                      // Provides cin, cout, and endl
    using namespace std;                                     // Allows standard-library names without the std:: prefix

    void displayMenu();
    void registerAttendee(int &availableSeats, int maxSeats);
    void cancelRegistration(int &availableSeats, int maxSeats);

    int main() {                                             // Starts the program
        int maxSeats;                                        // Stores the fixed workshop capacity
        int availableSeats;                                  // Stores the changing number of available seats
        int menuChoice;                                      // Stores one selected menu option

        cout << "Enter the maximum number of seats: ";
        cin >> maxSeats;

        while (maxSeats <= 0) {
            cout << "Seats must be greater than zero. Try again: ";
            cin >> maxSeats;
        }

        availableSeats = maxSeats;

        do {
            displayMenu();
            cout << "Select an option: ";
            cin >> menuChoice;

            switch (menuChoice) {
                case 1:
                    registerAttendee(availableSeats, maxSeats);
                    break;
                case 2:
                    cancelRegistration(availableSeats, maxSeats);
                    break;
                case 3:
                    cout << "Ending workshop registration session.\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }

            cout << "Available seats: " << availableSeats << endl;
        } while (menuChoice != 3);

        return 0;                                            // Ends the program successfully
    }                                                        // Ends the main function

    void displayMenu() {
        cout << "\nWorkshop Registration Menu\n";
        cout << "1. Register attendee\n";
        cout << "2. Cancel registration\n";
        cout << "3. Exit\n";
    }

    void registerAttendee(int &availableSeats, int maxSeats) {
        if (availableSeats > 0) {
            availableSeats--;
            cout << "Attendee registered successfully.\n";
        } else {
            cout << "No seats available.\n";
        }

        cout << "Current available seats: " << availableSeats << " of " << maxSeats << endl;
    }

    void cancelRegistration(int &availableSeats, int maxSeats) {
        if (availableSeats < maxSeats) {
            availableSeats++;
            cout << "Registration canceled successfully.\n";
        } else {
            cout << "No registrations to cancel.\n";
        }

        cout << "Current available seats: " << availableSeats << " of " << maxSeats << endl;
    }

    /*
    Test Cases:
    1. maxSeats = 5, register attendee -> availableSeats becomes 4
    2. maxSeats = 5, cancel registration after one registration -> availableSeats becomes 5
    3. maxSeats = 0 -> invalid and the program asks again
    4. maxSeats = 5, attempt to register when availableSeats = 0 -> no seats available

    Analysis:
    maxSeats does not need & because it is only a limit value.
    availableSeats needs & because the function must change the real value in main().
    */