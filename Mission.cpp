#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mission.h"
#include <string>
using namespace std;


// Accessors
string Mission::GetName() const {
    return missionName;
}

// Mutators
void Mission::SetName(const string& name) {
    missionName = name;
}

void Mission::SetDifficulty(int d) {
   difficulty = d; 
}