#ifndef MISSIONH
#define MISSIONH
#include <string>
using namespace std;

class Mission {
   private:
      string missionName;
      int difficulty;
      int rewardCredits;
      int rewardReputation;
      int energyCost;
   
   public:
      Mission(string n, int d, int rC, int rR, int eC);
      void SetName(const string& name);
      string GetName() const;


      void PrintInfo() const;
   
};

#endif