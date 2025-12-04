#pragma once
#include <vector>
#include "wind_record.h"

using namespace std;

typedef int (*ComparatorFunc)(const WindRecord*, const WindRecord*);

void shakerSort(vector<WindRecord*>& records, ComparatorFunc comparator);
void mergeSort(vector<WindRecord*>& records, ComparatorFunc comparator);
