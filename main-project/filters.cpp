#include "filters.h"
#include <algorithm>

using namespace std;

vector<WindRecord> filterByWestDirections(const vector<WindRecord>& records) {
    vector<WindRecord> result;
    for (const auto& record : records) {
        if (record.direction == West || record.direction == NorthWest || record.direction == North) {
            result.push_back(record);
        }
    }
    return result;
}

vector<WindRecord> filterBySpeedAbove5(const vector<WindRecord>& records) {
    vector<WindRecord> result;
    for (const auto& record : records) {
        if (record.speed > 5.0) {
            result.push_back(record);
        }
    }
    return result;
}