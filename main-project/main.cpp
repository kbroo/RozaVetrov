#include <iostream>
#include <iomanip>
#include <vector>
#include "file_reader.h"
#include "file_reader.cpp"
#include "filters.h"
#include "sorts.h"
#include "comparators.h"

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
        case 4: {
            vector<WindRecord*> recordPtrs;
            for (auto& record : records) {
                recordPtrs.push_back(&record);
            }

            cout << "\n--- Select Sort Method ---\n";
            cout << "1. Shaker Sort\n";
            cout << "2. Merge Sort\n";
            int sortMethod;
            cin >> sortMethod;

            cout << "\n--- Select Sort Criteria ---\n";
            cout << "1. By speed (descending)\n";
            cout << "2. By direction, month, day (ascending)\n";
            int compareMethod;
            cin >> compareMethod;

            void (*sortFuncs[])(vector<WindRecord*>&, ComparatorFunc) = {
                shakerSort,
                mergeSort
            };

            ComparatorFunc compareFuncs[] = {
                compareBySpeedDescending,
                compareByDirectionMonthDay
            };

            if (sortMethod >= 1 && sortMethod <= 2 && compareMethod >= 1 && compareMethod <= 2) {
                sortFuncs[sortMethod - 1](recordPtrs, compareFuncs[compareMethod - 1]);

                cout << "\n=== Sorted Records ===" << endl;
                for (const auto* record : recordPtrs) {
                    printRecord(*record);
                }
            }
            else {
                cout << "Invalid choice!" << endl;
            }
            break;
        }
        case 0:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}