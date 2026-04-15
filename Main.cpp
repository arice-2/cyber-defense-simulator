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

    Player myPlayer;
    myPlayer.SetName(playerName);

    /**
     * Read in missions from missions.txt file. This way, the values of the missions can be easily changed.
     */


    // Main game loop. This allows the player to select the activity they want to do, or quit the game at any time.
    bool playGame = true;
    while (playGame) {
        cout << "\nMenu:" << endl;
        cout << "1. View Status" << endl;
        cout << "2. Train" << endl;
        cout << "3. Rest" << endl;
        cout << "4. Shop" << endl;
        cout << "5. Attempt Mission" << endl;
        cout << "6. Exit Simulation" << endl;
        cout << "Choose an action (1-6): ";
        
        int choice;
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting simulation..." << endl;
            break;
        }

        switch (choice) {
            case 1:
                myPlayer.PrintInfo();
                playGame = false;
            case 2:
                cout << "Training..." << endl;
                // Implement training logic
                playGame = false;
            case 3:
                cout << "Resting..." << endl;
                // Implement resting logic
                playGame = false;
            case 4:
                cout << "Shopping..." << endl;
                // Implement shopping logic
                playGame = false;
            case 5:
                cout << "Attempting mission..." << endl;
                // Implement mission attempt logic
                bplayGame = false;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

/*
   int userYear;
   int userPrice;
   int userCurrentYear;
   Car myCar;
      
   cin >> userYear;
   cin >> userPrice;
   cin >> userCurrentYear;
      
   myCar.SetModelYear(userYear);
   myCar.SetPurchasePrice(userPrice);
   myCar.CalcCurrentValue(userCurrentYear);
      
   myCar.PrintInfo();
*/
   
   return 0;
}