//Juan Gonzalez
//CS210 Project 3
//06/22/2025

#include <iostream>
#include <limits>  // For numeric_limits
#include "GroceryTracker.h"

using namespace std;

int main() {
    GroceryTracker tracker;

    tracker.LoadData("CS210_Project_Three_Input_File.txt");
    tracker.WriteBackupFile("frequency.dat");

    int choice;
    string item;

    do {
        cout << "\n===== Corner Grocer Menu =====\n";
        cout << "1. Search for an item\n";
        cout << "2. Display all item frequencies\n";
        cout << "3. Display histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Validate input is an integer between 1 and 4
        while (!(cin >> choice) || choice < 1 || choice > 4) {
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }

        switch (choice) {
        case 1:
            cout << "Enter item name: ";
            cin >> item;
            cout << item << " was purchased "
                << tracker.GetItemFrequency(item) << " times.\n";
            break;
        case 2:
            cout << "\nItem Frequencies:\n";
            tracker.PrintFrequencies();
            break;
        case 3:
            cout << "\nPurchase Histogram:\n";
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Thank you!\n";
            break;
        }

    } while (choice != 4);

    return 0;
}