#pragma once
#include <string>

using namespace std;

enum WindDirection {
    North,
    NorthEast,
    East,
    SouthEast,
    South,
    SouthWest,
    West,
    NorthWest
};

struct WindRecord {
    int day;
    int month;
    WindDirection direction;
    double speed;
};
