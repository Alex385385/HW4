#include <iostream>
#include <cstdlib>
using namespace std;

class Die
{
private:
   int sides;
   int value;
public:
   Die()
   {
      unsigned seed = time(0);

      srand(seed);
      sides = 6;
      roll();
   }
   void roll()
   {
      const int MIN_VALUE = 1;
      value = (rand() % (sides - MIN_VALUE + 1)) + MIN_VALUE;
   }
   int getValue()
   {
      return value;
   }
};

int rollValue()
{
   int roll1, roll2;
   Die d;

   //d.roll();
   roll1 = d.getValue();
   d.roll();
   roll2 = d.getValue();

   return roll1 + roll2;
}

bool play()
{
   char answer;
   cout << "Roll the dice? (y/n): ";
   cin >> answer;

   if(answer == 'Y' || answer == 'y')
   {
      return true;
   }
   else
   {
      return false;
   }
}
void result(int pcScore, int userScore)
{
   if(userScore > pcScore && userScore <= 21)
   {
      cout << "You win" << endl;
   }
   else if(userScore <= 21 && pcScore > 21)
   {
      cout << "You win" << endl;
   }
   else if(userScore == 21 && pcScore != 21)
   {
      cout << "You win" << endl;
   }
   else if(userScore == pcScore)
   {
      cout << "Tie " << endl;
   }
   else if(userScore > 21 && pcScore > 21)
   {
      cout << "No Winner" << endl;
   }
   else
   {
      cout << "You Lose" << endl;
   }
   cout << "Computer Points " << pcScore << endl;
}

int main()
{
   int userPoints, pcPoints;

   cout << "Welcome to the game of 21!" << endl;

   while(play())
   {
      pcPoints += rollValue();
      userPoints += rollValue();

      if(userPoints > 21)
      {
         cout << "User is over 21" << endl;
         break;
      }

      cout << "User Points: " << userPoints << endl;
   }

   if(userPoints == 0 && pcPoints == 0)
   {
      cout << "You did not play: " << endl;
   }
   else
   {
      result(pcPoints, userPoints);
   }
}
