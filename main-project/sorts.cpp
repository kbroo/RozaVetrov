#include "sorts.h"
#include <algorithm>

using namespace std;

void shakerSort(vector<WindRecord*>& records, ComparatorFunc comparator) {
    int left = 0;
    int right = records.size() - 1;

    while (left < right) {
        // Forward pass
        for (int i = left; i < right; i++) {
            if (comparator(records[i], records[i + 1]) > 0) {
                swap(records[i], records[i + 1]);
            }
        }
        right--;

        // Backward pass
        for (int i = right; i > left; i--) {
            if (comparator(records[i - 1], records[i]) > 0) {
                swap(records[i - 1], records[i]);
            }
        }
        left++;
    }
}

void merge(vector<WindRecord*>& records, int left, int mid, int right, ComparatorFunc comparator) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<WindRecord*> L(n1);
    vector<WindRecord*> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = records[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = records[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (comparator(L[i], R[j]) <= 0) {
            records[k] = L[i];
            i++;
        }
        else {
            records[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        records[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        records[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(vector<WindRecord*>& records, int left, int right, ComparatorFunc comparator) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortRecursive(records, left, mid, comparator);
        mergeSortRecursive(records, mid + 1, right, comparator);
        merge(records, left, mid, right, comparator);
    }
}

void mergeSort(vector<WindRecord*>& records, ComparatorFunc comparator) {
    if (!records.empty()) {
        mergeSortRecursive(records, 0, records.size() - 1, comparator);
    }
}