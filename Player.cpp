#include <iostream>
#include <iomanip>
#include <cmath>
#include "Player.h"
#include <string>
using namespace std;

Player::Player(string n) {
    playerName = n;
    energy = 100;
    skillLevel = 20;
    credits = 50;
    reputation = 0;
    toolLevel = "Basic Laptop";
    missionsCompleted = 0;
    daysUsed = 0;
}

// Accessors
string Player::GetName() const {
    return playerName;
}

int Player::GetEnergy() const {
    return energy;
}

int Player::GetSkillLevel() const {
    return skillLevel;
}

int Player::GetCredits() const {
    return credits;
}

int Player::GetReputation() const {
    return reputation;
}

string Player::GetToolLevel() const {
    return toolLevel;
}

int Player::GetMissionsCompleted() const {
    return missionsCompleted;
}

int Player::GetDaysUsed() const {
    return daysUsed;
}

int Player::GetFinalScore() const {
    return (energy + skillLevel*10 + credits + reputation*20 + missionsCompleted*10);
}

// Mutators
void Player::SetName(const string& name) {
    playerName = name;
}

void Player::SetEnergy(int e) {
    energy = e;
}

void Player::SetSkillLevel(int skill) {
    skillLevel = skill;
}

void Player::SetCredits(int c) {
    credits = c;
}

void Player::SetReputation(int r) {
    reputation = r;
}

void Player::SetToolLevel(string tL) {
    toolLevel = tL;
}

void Player::SetMissionsCompleted(int mC) {
    missionsCompleted = mC;
}

void Player::SetDaysUsed(int dU) {
    daysUsed = dU;
}

// Other methods
void Player::ViewStatus() const {
   cout << fixed << setprecision(2);
   cout << "***** Player information *****" << endl;
   cout << "Name: " << GetName() << endl;
   cout << "Energy: " << GetEnergy() << endl;
   cout << "Skill Level: " << GetSkillLevel() << endl;
   cout << "Credits: " << GetCredits() << endl;
   cout << "Reputation: " << GetReputation() << endl;
   cout << "Current Tool: " << GetToolLevel() << endl;
   cout << "Missions Completed: " << GetMissionsCompleted() << endl;
}