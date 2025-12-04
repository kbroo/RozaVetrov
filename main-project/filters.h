#pragma once
#include <vector>
#include "wind_record.h"

using namespace std;

vector<WindRecord> filterByWestDirections(const vector<WindRecord>& records);
vector<WindRecord> filterBySpeedAbove5(const vector<WindRecord>& records);