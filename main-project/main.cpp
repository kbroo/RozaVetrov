#include <iostream>
#include <iomanip>
#include "file_reader.h"
#include "filters.h"
#include "file_reader.cpp"

using namespace std;

void printRecord(const WindRecord& record) {
    cout << "Day: " << setw(2) << setfill('0') << record.day
        << " Month: " << setw(2) << setfill('0') << record.month
        << " | Direction: " << directionToString(record.direction)
        << " | Speed: " << fixed << setprecision(1) << record.speed << " m/s"
        << endl;
}

void printRecords(const vector<WindRecord>& records, const string& title) {
    cout << "\n=== " << title << " (" << records.size() << " records) ===" << endl;
    for (const auto& record : records) {
        printRecord(record);
    }
}

int main() {
    cout << "Wind Rose Tracker" << endl;
    cout << "Variant: Wind Rose" << endl;
    cout << "Author: Petrov Petr" << endl;
    cout << "Group: PI-401" << endl;

    auto records = readDataFromFile("data.txt");

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Show all records\n";
        cout << "2. Filter: West, NorthWest, North directions\n";
        cout << "3. Filter: Speed > 5 m/s\n";
        cout << "4. Sort records\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            printRecords(records, "All Records");
            break;
        case 2:
            printRecords(filterByWestDirections(records), "West Directions");
            break;
        case 3:
            printRecords(filterBySpeedAbove5(records), "Speed > 5 m/s");
            break;
        case 4:
            // Sorting will be added in next step
            break;
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}