#include "file_reader.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

WindDirection parseDirection(const string& dirStr) {
    if (dirStr == "North") return North;
    if (dirStr == "NorthEast") return NorthEast;
    if (dirStr == "East") return East;
    if (dirStr == "SouthEast") return SouthEast;
    if (dirStr == "South") return South;
    if (dirStr == "SouthWest") return SouthWest;
    if (dirStr == "West") return West;
    if (dirStr == "NorthWest") return NorthWest;
    return North; // Default
}

string directionToString(WindDirection dir) {
    switch (dir) {
    case North: return "North";
    case NorthEast: return "NorthEast";
    case East: return "East";
    case SouthEast: return "SouthEast";
    case South: return "South";
    case SouthWest: return "SouthWest";
    case West: return "West";
    case NorthWest: return "NorthWest";
    default: return "Unknown";
    }
}

vector<WindRecord> readDataFromFile(const char* filename) {
    vector<WindRecord> records;
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return records;
    }

    string line;
    while (getline(file, line) && records.size() < MAX_RECORDS) {
        stringstream ss(line);
        WindRecord record;
        string dirStr;

        ss >> record.day >> record.month >> dirStr >> record.speed;
        record.direction = parseDirection(dirStr);

        records.push_back(record);
    }

    file.close();
    return records;
}