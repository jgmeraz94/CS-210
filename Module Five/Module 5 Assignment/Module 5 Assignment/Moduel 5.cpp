//Juan Gonzalez
//Module 5 Assignment
//06/06/2025

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    // Variables to hold city name and Fahrenheit temperature
    string city;
    int fahrenheit;

    // Open input file containing city names and Fahrenheit temperatures
    ifstream inputFile("FahrenheitTemperature.txt");

    // Open output file where we’ll write the converted Celsius temperatures
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if input file opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1; // Exit the program with an error code
    }

    // Check if output file opened successfully
    if (!outputFile) {
        cerr << "Error: Could not create output file." << endl;
        return 1; // Exit the program with an error code
    }

    // Read from input file line by line (city and its Fahrenheit temperature)
    while (inputFile >> city >> fahrenheit) {
        // Convert Fahrenheit to Celsius using the formula: (F - 32) * 5 / 9
        double celsius = (fahrenheit - 32) * 5.0 / 9.0;

        // Write the city name and its Celsius temperature to the output file
        outputFile << city << " " << celsius << endl;
    }

    // Close both files
    inputFile.close();
    outputFile.close();

    // Confirmation message to the user
    cout << "Conversion complete. Check CelsiusTemperature.txt." << endl;

    return 0;
}