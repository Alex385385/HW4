#include <iostream>
#include <string>
using namespace std;

class Ship
{
private:
   string shipName;
   string yearBuilt;
public:
   Ship()
   {
      shipName = "";
      yearBuilt = "";
   }
   Ship(string name, string built)
   {
      shipName = name;
      yearBuilt = built;
   }
   void setShipName(string n)
   {
      shipName = n;
   }
   void setShipBuilt(string b)
   {
      yearBuilt = b;
   }
   string getShipName()
   {
      return shipName;
   }
   string getYearBuilt()
   {
      return yearBuilt;
   }
   virtual void print()
   {
      cout << "Ships Name" << getShipName() << endl;
      cout << "Year Built" << getYearBuilt() << endl;
   }
};

class CruiseShip : public Ship
{
private:
   int numPassangers;
public:
   CruiseShip(string name, string built, int num) : Ship(name, built)
   {
      numPassangers = num;
   }
   void setNumPassangers(int n)
   {
      numPassangers = n;
   }
   int getNumPassangers()
   {
      return numPassangers;
   }
   void print()
   {
      cout << "Ship Name: " << getShipName() << endl;
      cout << "Max Capacity: " << getNumPassangers() << endl;
   }
};

class CargoShip : public Ship
{
private:
   int capacity;
public:
   CargoShip(string name, string built,int c) : Ship(name, built)
   {
      capacity = c;
   }
   void setCapacity(int c)
   {
      capacity = c;
   }
   int getCapacity()
   {
      return capacity;
   }
   void print()
   {
      cout << "Ship Name: " << getShipName() << endl;
      cout << "Cargo Capacity: " << getCapacity() << endl;
   }
};

int main()
{
   Ship *array[4] = {new Ship("Marry", "2008"),
                     new CruiseShip("SS Reel", "2010", 4000),
                     new CargoShip("SS Tough", "1990", 8000),
                     new CargoShip("SS Cargo", "2008", 20000)};

   for(int i = 0; i < 4; i++)
   {
      *array[i]->print();
   }

   return 0;
}
