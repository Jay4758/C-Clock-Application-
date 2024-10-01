#include <iostream>
using namespace std;

// Here, I’m declaring the functions I’ll use in my program later.
void displayClocks(int hour12, int hour24, int minute, int second);
void addHour(int& hour12, int& hour24);
void addMinute(int& minute, int& hour12, int& hour24);
void addSecond(int& second, int& minute, int& hour12, int& hour24);

int main() {
    // Initializing the clock times. I set both clocks to start at 12:00:00.
    int hour12 = 12, hour24 = 0, minute = 0, second = 0;
    int choice;  // This will store the menu choice from the user.

    do {
        // Display the clocks every time before showing the menu.
        displayClocks(hour12, hour24, minute, second);

        // This is my simple menu for the user to interact with.
        cout << "\nMenu:\n";
        cout << "1. Add Hour\n";
        cout << "2. Add Minute\n";
        cout << "3. Add Second\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Here, I’m getting the user’s input.

        // I’m using a switch statement to decide what happens based on the user’s choice.
        switch (choice) {
        case 1:
            addHour(hour12, hour24);
            break;
        case 2:
            addMinute(minute, hour12, hour24);
            break;
        case 3:
            addSecond(second, minute, hour12, hour24);
            break;
        case 4:
            cout << "Exiting the program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);  // Keep looping the menu until the user chooses to exit.

    return 0;
}

// This function shows the 12-hour and 24-hour clocks in the correct format.
void displayClocks(int hour12, int hour24, int minute, int second) {
    cout << "12-Hour Clock: "
        << (hour12 < 10 ? "0" : "") << hour12 << ":"
        << (minute < 10 ? "0" : "") << minute << ":"
        << (second < 10 ? "0" : "") << second << endl;

    cout << "24-Hour Clock: "
        << (hour24 < 10 ? "0" : "") << hour24 << ":"
        << (minute < 10 ? "0" : "") << minute << ":"
        << (second < 10 ? "0" : "") << second << endl;
}

// This function adds an hour to both the 12-hour and 24-hour clocks.
void addHour(int& hour12, int& hour24) {
    hour12 = (hour12 % 12) + 1;  // The 12-hour clock resets after 12.
    hour24 = (hour24 + 1) % 24;  // The 24-hour clock resets after 24.
}

// This function adds a minute, and if it hits 60, it adds an hour too.
void addMinute(int& minute, int& hour12, int& hour24) {
    minute++;
    if (minute == 60) {
        minute = 0;
        addHour(hour12, hour24);  // If minutes go over 60, reset and add an hour.
    }
}

// This function adds a second, and if it hits 60, it adds a minute too.
void addSecond(int& second, int& minute, int& hour12, int& hour24) {
    second++;
    if (second == 60) {
        second = 0;
        addMinute(minute, hour12, hour24);  // If seconds go over 60, reset and add a minute.
    }
}

