#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <string>
#include <map>
using namespace std;

// Class that handles tracking grocery item frequencies
class GroceryTracker {
private:
    map<string, int> itemFrequency;  // Stores item names and their frequencies

public:
    void LoadData(const string& filename);              // Loads data from file
    int GetItemFrequency(const string& item);           // Returns frequency of a given item
    void PrintFrequencies();                            // Displays all item frequencies
    void PrintHistogram();                              // Displays histogram of item frequencies
    void WriteBackupFile(const string& filename);       // Writes frequency data to a backup file
};

#endif