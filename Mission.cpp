#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mission.h"
#include <string>
using namespace std;

// Constructor
Mission::Mission(string n, int d, int rC, int rR, int eC) {
    missionName = n;
    difficulty = d;
    rewardCredits = rC;
    rewardReputation = rR;
    energyCost = eC;
}

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
void Mission::SetName(string name) {
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