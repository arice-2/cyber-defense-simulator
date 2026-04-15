#include <iostream>
#include <iomanip>
#include <cmath>
#include "Player.h"
#include <string>
using namespace std;

// Accessors
string Player::GetName() const {
    return playerName;
}

int Player::GetEnergy() {
    return energy;
}

int Player::GetSkillLevel() {
    return skillLevel;
}

int Player::GetCredits() {
    return credits;
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

// Other methods
void Player::PrintInfo() const {
   cout << fixed << setprecision(2);
   cout << "Player's information:" << endl;
   cout << "Name: " << GetName() << endl;
}