#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mission.h"
#include <string>
using namespace std;


// Mutators
void Mission::SetName(const string& name) {
    missionName = name;
}

// Accessors
string Mission::GetName() const {
    return missionName;
}



void Mission::PrintInfo() const {
   cout << fixed << setprecision(2);
   cout << "Mission's information:" << endl;
   cout << "Name: " << GetName() << endl;
}