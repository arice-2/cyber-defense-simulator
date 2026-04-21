#include <iostream>
#include "Car.h"
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
    Player myPlayer;
    myPlayer.SetName(playerName);

    /**
     * Read in missions from missions.txt file. This way, the values of the missions can be easily changed.
     */


    // Main game loop. This allows the player to select the activity they want to do, or quit the game at any time.
    bool playGame = true;
    while (playGame) {

        if (myPlayer.GetDaysUsed() >= 12) {
            playGame = false;
            break;
        }
        else if (myPlayer.GetEnergy <= 0) {
            playGame = false;
            break;
        }

        cout << "\nMenu:" << endl;
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
            case 1:
                myPlayer.ViewStatus();
                break;
            case 2:
                int skillIncrease = ((rand() % 20) + 5);
                int energyDecrease = ((rand() % 10) + 5);

                cout << "Training..." << endl;
                cout << "You've bettered your cybersecurity skills!" << endl;
                cout << "Skill increased by " << (string) skillIncrease << endl;
                cout << "Energy decreased by " << (string) energyDecrease << endl;

                myPlayer.SetSkillLevel(myPlayer.GetSkillLevel() + skillIncrease);
                myPlayer.SetEnergy(myPlayer.GetEnergy() - energyDecrease);

                break;
            case 3:
                int energyIncrease = ((rand() % 10) + 5);

                cout << "Resting..." << endl;
                cout << "Energy increased by " << (string) energyIncrease << endl;
                break;
            case 4:
                cout << "Shopping..." << endl;
                // Implement shopping logic
                break;
            case 5:
                cout << "Available Missions:" << endl;
                cout << 
                // Implement mission attempt logic
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        myPlayer.DaysUsed(myPlayer.GetDaysUsed() + 1);
    }

    cout << "***** Final Report: *****" << endl;
    cout << "Player: " << playerName << endl << endl;

    cout << "Energy: " << myPlayer.GetEnergy() << endl;
    cout << "Skill: " << myPlayer.GetSkill() << endl;
    cout << "Credits: " << myPlayer.GetCredits() << endl;
    cout << "Reputation: " << myPlayer.GetReputation() << endl;
    cout << "Missions Completed: " << myPlayer.GetMissionsCompleted() << endl;
    
    cout << "Final Score: " << myPlayer.GetFinalScore() << endl;
   
   return 0;
}