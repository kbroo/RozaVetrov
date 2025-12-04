#include <iostream>
#include "file_reader.h"

using namespace std;

int main() {

    cout << "Roza vetrov" << endl;
    cout << "Variant: 6" << endl;
    cout << "Author: Kvit Ilya" << endl;
    cout << "Group: PI-401" << endl;

    auto records = readDataFromFile("data.txt");
    cout << "\nRecords loaded: " << records.size() << endl;

    return 0;

}