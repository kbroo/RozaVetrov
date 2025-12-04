#include "comparators.h"

int compareBySpeedDescending(const WindRecord* a, const WindRecord* b) {
    if (a->speed > b->speed) return -1;
    if (a->speed < b->speed) return 1;
    return 0;
}

int compareByDirectionMonthDay(const WindRecord* a, const WindRecord* b) {
    if (a->direction < b->direction) return -1;
    if (a->direction > b->direction) return 1;

    // If directions are equal, compare by month
    if (a->month < b->month) return -1;
    if (a->month > b->month) return 1;

    // If months are equal, compare by day
    if (a->day < b->day) return -1;
    if (a->day > b->day) return 1;

    return 0;
}