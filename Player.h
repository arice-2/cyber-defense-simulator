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
      Player(string n);
      void SetName(const string& name);
      void SetEnergy(int energy);
      void SetSkillLevel(int skill);
      void SetCredits(int c);
      void SetReputation(int r);
      void SetToolLevel(int tL);
      void SetMissionsCompleted(int mC);
      void SetDaysUsed(int dU);

      string GetName() const;
      int GetEnergy() const;
      int GetSkillLevel() const;
      int GetCredits() const;
      int GetReputation() const;
      int GetToolLevel() const;
      int GetMissionsCompleted() const;
      int GetDaysUsed() const;
      int GetFinalScore() const;

      void ViewStatus() const;
   
};

#endif