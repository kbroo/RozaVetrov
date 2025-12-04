#pragma once
#include <vector>
#include "wind_record.h"

using namespace std;

vector<WindRecord> readDataFromFile(const char* filename);