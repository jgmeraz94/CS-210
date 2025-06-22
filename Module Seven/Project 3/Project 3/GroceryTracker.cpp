#include "GroceryTracker.h"
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// LoadData: Reads items from a file and updates their frequency in a map
void GroceryTracker::LoadData(const string& filename) {
    ifstream inputFile(filename);
    string item;

    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    while (inputFile >> item) {
        ++itemFrequency[item];
    }

    inputFile.close();
}

// GetItemFrequency: Returns the frequency count of a given item
int GroceryTracker::GetItemFrequency(const string& item) {
    if (itemFrequency.count(item)) {
        return itemFrequency[item];
    }
    return 0;
}

// PrintFrequencies: Prints a list of all items with their frequencies
void GroceryTracker::PrintFrequencies() {
    for (const auto& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// PrintHistogram: Displays asterisks to represent each item's frequency
void GroceryTracker::PrintHistogram() {
    for (const auto& pair : itemFrequency) {
        cout << setw(12) << left << pair.first << " ";
        cout << string(pair.second, '*') << endl;
    }
}

// WriteBackupFile
// This method creates a backup file with all item frequencies.
// It writes each item and its frequency to a file in the format: ItemName Frequency
void GroceryTracker::WriteBackupFile(const string& filename) {
    ofstream outFile(filename); // Open output file stream with given filename

    // Check if file was opened successfully
    if (!outFile) {
        cerr << "Error: Unable to open output file: " << filename << endl;
        return;
    }

    // Iterate over the itemFrequency map and write each item and count to the file
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close(); // Close the output file to ensure data is saved
}
