#ifndef MISSIONH
#define MISSIONH
#include <string>
using namespace std;

class Mission {
   private:

      // Class variables
      string missionName;
      int difficulty;
      int rewardCredits;
      int rewardReputation;
      int energyCost;
   
   public:
      // Constructor
      Mission(string n, int d, int rC, int rR, int eC);

      // Accessors
      string GetName() const;
      int GetDifficulty() const;
      int GetRewardCredits() const;
      int GetRewardReputation() const;
      int GetEnergyCost() const;

      // Mutators
      void SetName(string name);
      void SetDifficulty(int n);
      void SetRewardCredits(int r);
      void SetRewardReputation(int r);
      void SetEnergyCost(int e);
   
};

#endif