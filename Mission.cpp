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

int Mission::GetDifficulty() const {
    return difficulty;
}

int Mission::GetRewardCredits() const {
    return rewardCredits;
}

int Mission::GetRewardReputation() const {
    return rewardReputation;
}

int Mission::GetEnergyCost() const {
    return energyCost;
}

// Mutators
void Mission::SetName(const string& name) {
    missionName = name;
}

void Mission::SetDifficulty(int d) {
   difficulty = d; 
}

void Mission::SetRewardCredits(int rC) {
    rewardCredits = rC;
}

void Mission::SetRewardReputation(int rR) {
    rewardReputation = rR;
}

void Mission::SetEnergyCost(int eC) {
    energyCost = eC;
}