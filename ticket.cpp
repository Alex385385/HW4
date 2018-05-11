#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class ParkedCar
{
private:
   string make;
   string model;
   string color;
   string licenseNum;
   int minutes;
public:
   ParkedCar()
   {
       make = "";
       model = "";
       color = "";
       licenseNum = "";
       minutes = 0;
   }
   ParkedCar(string ma, string mo, string col, string lic, int min)
   {
      make = ma;
      model = mo;
      color = col;
      licenseNum = lic;
      minutes = min;
   }
   void setMake(string m)
   {
      make = m;
   }
   void setModel(string m)
   {
      model = m;
   }
   void setColor(string c)
   {
      color = c;
   }
   void setLicNum(string l)
   {
      licenseNum = l;
   }
   void setMinutes(int m)
   {
      minutes = m;
   }
   string getMake()
   {
      return make;
   }
   string getModel()
   {
      return model;
   }
   string getColor()
   {
      return color;
   }
   string getLicNum()
   {
      return licenseNum;
   }
   int getMinutes()
   {
      return minutes;
   }
};

class ParkingMeter
{
private:
   int minutesPurchased;
public:
   ParkingMeter()
   {
       minutesPurchased = 0;
   }
   ParkingMeter(int min)
   {
      minutesPurchased = min;
   }
   void setMinutesPurchased(int m)
   {
      minutesPurchased = m;
   }
   int getMinutesPurchased()
   {
      return minutesPurchased;
   }
};

class PoliceOfficer
{
private:
   string name;
   string badgeNumber;
public:
   PoliceOfficer()
   {
      name = "";
      badgeNumber = "";
   }
   PoliceOfficer(string nam, string num)
   {
      name = nam;
      badgeNumber = num;
   }
   bool inspect(ParkedCar& c, ParkingMeter& m)
   {
      if((m.getMinutesPurchased() - c.getMinutes()) < 0)
      {
         return true;
      }
      else
      {
         return false;
      }
   }
};

class ParkingTicket
{
private:
   int fineAmount;
   ParkedCar car;
   ParkingMeter meter;
   PoliceOfficer officer;
public:
   ParkingTicket(ParkedCar &c, ParkingMeter &m, PoliceOfficer &p)
   {
      car = c;
      meter = m;
      officer = p;
      fineAmount = FineAmount();
   }
   int FineAmount()
   {
      return(25 + 10 * (ceil((car.getMinutes()- meter.getMinutesPurchased())/60.0) - 1));
   }
   void print()
   {
      cout << "The driver will recieve a ticket of $" << FineAmount() << endl;
   }
};

int main()
{
   string carMake, carModel, carColor, carLic, name, badgeNum;
   int minutesParked, purchasedMinutes;

   cout << "Enter car make: ";
   cin >> carMake;
   cout << "Model: ";
   cin >> carModel;
   cout << "Color: ";
   cin >> carColor;
   cout << "Licence Number: ";
   cin >> carLic;

   do
   {
      cout << "How many minutes has the car been parked? ";
      cin >>minutesParked;
   }while(minutesParked < 0);

   ParkedCar car(carMake, carModel, carColor, carLic, minutesParked);

   do
   {
      cout << "How many minutes where purchased? ";
      cin >> purchasedMinutes;
   }while(purchasedMinutes < 0);

   ParkingMeter meter(purchasedMinutes);

   cout << "Police Officer Info: " << endl;
   cout << "Name: ";
   cin >> name;
   cout << "Badge Number: ";
   cin >> badgeNum;

   PoliceOfficer officer(name, badgeNum);

   if(officer.inspect(car, meter) == true)
   {
      ParkingTicket ticket(car, meter, officer);
      ticket.print();
   }
   else
   {
      cout << "No Ticket" << endl;
   }

   return 0;
}
