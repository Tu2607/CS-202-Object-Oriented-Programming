//Tu Vu CS202
//Program 2
//October 23, 2018
//Purpose of the file: The head files for the abstract base class and its hierarchy.  The transport class in this program is a virtual base class so this program can't
//create any object that have type transport.  All of its derived class must have a display function since the display function of the Abstract Base Class is a pure 
//virtual function.

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;


class transport
{
	public:
		transport ();
		transport (bool repair_stat,float hours, int identifier, char * L1, char * L2, int id, int cost); //Constructor with arguments 
		transport (const transport & to_copy);
		virtual ~transport(); //Virtual destructor

		//Getters//
		int getID(); //Specifically for the removal of a node
		int getCost();
		int getType();

		//This function makes the class an abstract base class	
		virtual void display_all() = 0; //This forces all the derived class to have a display_location function.	
	protected:
		char * loc1;
		char * loc2;
		int transport_id;
		int transport_cost;
		int type; //This here is a flag that indicate where the node is a scooter, a zipcar, or a bike this will help a lot when trying to total the cost of each type vehicle.
		bool repair;
		float rent_hours;
		
};


class scooter: public transport
{
	public: //The constructors.
		scooter();
		scooter (bool repair_stat, float hours, int identifier,int batteryLvl, char * scootLoc1, char * scootLoc2, int id, int cost); //Constructor with arg
		scooter (const scooter & to_copy);
		~scooter ();
		
		void display_all();
		
	protected:
		int battLevel;
};


class zipCar: public transport
{
	public:
		zipCar();
		zipCar(const zipCar & to_copy); //Copy constructor
		zipCar (bool repair_stat, float hours, int identifier, char * license, int gas, char * zipLoc1, char * zipLoc2, int id, int cost);//Constructor with arg
		~zipCar();

		void display_all();
		bool fillUp();

	protected:
		bool fill;
		char * plate;
		int gasCheck;
};

class bicycle: public transport //The bicycle class derived from the transport class
{
	public:
		bicycle();
		bicycle (const bicycle & to_copy);
		bicycle (bool repair_stat, float hours, int identifier, char * bikeLoc1, char * bikeLoc2, int id, int cost);
		~bicycle();

		void display_all();
		bool tire_check();
	protected:	
		bool tires;
};

