#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "Player.h"
#include "Mission.h"

using namespace std;

/*

main()
|
|--- initialize player
|--- create missions (vector)
|--- create tools (arrays)
|
|--- main game loop
    |
    |--- show menu
        |
        |--- user chooses action
                |
                |--- view status
                |--- train
                |--- rest
                |--- shop
                |--- attempt mission
        |
        |--- update player statistics
        |
|--- end simulation
|
|--- display final report

*/

int main() {

    // Welcome message and setting up player & mission objects.
    cout << "***** Welcome to the Cyber Defense Simulator! *****" << endl;
    cout << "Enter your name: ";
    string playerName;
    cin >> playerName;

    // Make player object
    Player myPlayer(playerName);

    // Initialize tools
    string toolNames[4] = {"Linux Laptop", "Packet Analyzer", "John the Ripper", "AI Defense Console"};
    int toolBonus[4] = {2, 11, 13, 19};
    int toolCost[4] = {15, 25, 45 , 75};

    /**
     * Read in missions from missions.txt file. This way, the values of the missions can be easily changed.
     */
    vector<Mission> missions;

    ifstream inputFile("Missions.txt");
    if (inputFile.is_open()) {
        string name;
        string delim;
        int dif;
        int rewardC;
        int rewardR;
        int energyC;
        
        while (getline(inputFile, name) && name != "+++++") {
            inputFile >> dif >> rewardC >> rewardR >> energyC;
            getline(inputFile, delim);
            getline(inputFile, delim);
            missions.push_back(Mission(name, dif, rewardC, rewardR, energyC));
        }
        inputFile.close();
    }


    // Main game loop. This allows the player to select the activity they want to do, or quit the game at any time.
    bool playGame = true;
    while (playGame) {

        if (myPlayer.GetDaysUsed() >= 12) {
            playGame = false;
            break;
        }
        else if (myPlayer.GetEnergy() <= 0) {
            playGame = false;
            break;
        }

        cout << "\nDay " << myPlayer.GetDaysUsed()+1 << " of 12" << endl;
        cout << "1. View Status" << endl;
        cout << "2. Train" << endl;
        cout << "3. Rest" << endl;
        cout << "4. Visit Shop" << endl;
        cout << "5. Attempt Mission" << endl;
        cout << "6. Quit Simulation" << endl;
        cout << "Choose an action (1-6): ";
        
        int choice;
        cin >> choice;

        // Player quit's the game
        if (choice == 6) {
            cout << "Exiting simulation..." << endl;
            break;
        }

        // Player chooses 1-5, which are some kind of action.
        switch (choice) {

            // View Status
            case 1: {
                myPlayer.ViewStatus();
                break;
            }

            // Train
            case 2: {
                int skillIncrease = ((rand() % 20) + 5);
                int energyDecrease = ((rand() % 10) + 5);

                cout << "\nTraining..." << endl;
                cout << "You've bettered your cybersecurity skills!" << endl;
                cout << "Skill increased by " << skillIncrease << endl;
                cout << "Energy decreased by " << energyDecrease << endl;

                myPlayer.SetSkillLevel(myPlayer.GetSkillLevel() + skillIncrease);
                myPlayer.SetEnergy(myPlayer.GetEnergy() - energyDecrease);
                break;
            }

            // Rest
            case 3: {
                int energyIncrease = ((rand() % 10) + 5);

                cout << "\nResting..." << endl;
                cout << "Energy increased by " << energyIncrease << endl;
                break;
            }

            // Visit shop
            case 4: {
                cout << "\n+++++ Tool Shop +++++" << endl;
                for (int i = 0; i < 4; i++) {
                    cout << i+1 << ". " << toolNames[i] << " (Cost: " << toolCost[i] << ")";
                    if (myPlayer.GetToolLevel() == toolNames[i]) {
                        cout << " [Owned]";
                    }
                    
                    cout << endl;
                }
                int choice;
                cin >> choice;
                if (choice < 4 && myPlayer.GetCredits() > toolCost[choice-1]) {
                    if (myPlayer.GetCredits() >= toolCost[choice]) {
                        myPlayer.SetCredits(myPlayer.GetCredits() - toolCost[choice]);
                        myPlayer.SetToolLevel(toolNames[choice-1]);
                        cout << "Purchased " << toolNames[choice] << "!" << endl;
                    }
                    else if (myPlayer.GetCredits() < toolCost[choice-1]) {
                        cout << "You don't have enough credits." << endl;
                    }
                    else if (choice > 4) {
                        cout << "Invalid option.";
                    }
                }
                break;
            }

            // Attempt mission
            case 5: {
                cout << "\nAvailable Missions:" << endl;
                for (int i = 0; i < missions.size(); i++) {
                    cout << i << ". " << missions[i].GetName() << endl;
                }
                int choice;
                cin >> choice;
                if (choice > 0 && choice <= missions.size()) {
                    Mission m = missions[choice - 1];
                    if (myPlayer.GetEnergy() >= m.GetEnergyCost()) {
                        int randomBoost = rand() % 21;
                        int power = myPlayer.GetSkillLevel() + randomBoost;
                        
                        myPlayer.SetEnergy(myPlayer.GetEnergy() - m.GetEnergyCost());
                        myPlayer.SetDaysUsed(myPlayer.GetDaysUsed() + 1);

                        if (power >= m.GetDifficulty()) {
                            cout << "Mission SUCCESS!" << endl;
                            myPlayer.SetCredits(myPlayer.GetCredits() + m.GetRewardCredits());
                            myPlayer.SetReputation(myPlayer.GetReputation() + m.GetRewardReputation());
                            myPlayer.SetMissionsCompleted(myPlayer.GetMissionsCompleted() + 1);
                            missions.erase(missions.begin() + (choice-1));
                        }
                        else {
                            cout << "Mission FAILURE!" << endl;
                        }
                    }
                    else {
                        cout << "Not enough energy!" << endl;
                    }
                }

                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        myPlayer.SetDaysUsed(myPlayer.GetDaysUsed() + 1);
    }

    // Display final report after game is over
    cout << "***** Final Report: *****" << endl;
    cout << "Player: " << playerName << endl << endl;

    cout << "Energy: " << myPlayer.GetEnergy() << endl;
    cout << "Skill: " << myPlayer.GetSkillLevel() << endl;
    cout << "Credits: " << myPlayer.GetCredits() << endl;
    cout << "Reputation: " << myPlayer.GetReputation() << endl;
    cout << "Missions Completed: " << myPlayer.GetMissionsCompleted() << endl;
    
    cout << "Final Score: " << myPlayer.GetFinalScore() << endl;

    // Determine ranks
    if (myPlayer.GetFinalScore() >= 260) {
        cout << "Rank: Elite Cyber Defender" << endl;
    }
    else if (myPlayer.GetFinalScore() < 260 && myPlayer.GetFinalScore() >= 200) {
        cout << "Advanced Analyst" << endl;
    }
    else if (myPlayer.GetFinalScore() < 200 && myPlayer.GetFinalScore() >= 120) {
        cout << "Junior Security Specialist" << endl;
    }
    else if (myPlayer.GetFinalScore() < 120 && myPlayer.GetFinalScore() >= 0) {
        cout << "Cybersecurity Intern" << endl;
    }
   
   return 0;
}