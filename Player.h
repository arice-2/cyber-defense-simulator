#ifndef PLAYERH
#define PLAYERH
#include <string>
using namespace std;

class Player {
   private:
      string playerName;
      int energy;
      int skillLevel;
      int credits;
      int reputation;
      int toolLevel;
      int missionsCompleted;
      int daysUsed;
   
   public:
      void SetName(const string& name);
      void SetEnergy(int energy);
      void SetSkillLevel(int skill);
      void SetCredits(int c);

      string GetName() const;
      int GetEnergy();
      int GetSkillLevel();
      int GetCredits();

      void PrintInfo() const;
   
};

#endif