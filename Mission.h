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
      void SetName(const string& name);
      string GetName() const;


      void PrintInfo() const;
   
};

#endif