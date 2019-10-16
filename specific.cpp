//Tu Vu CS202
//Program2
//October 23, 2018
//Purpose of the file: This file is to implement the abstract base class and its dervied class. 

#include "specific.h"

transport::transport(): loc1(NULL), loc2(NULL), transport_id(0), transport_cost(0), type(0), repair(false)
{

}
transport::transport(bool repair_stat, float hours, int identifier, char * L1, char * L2, int id, int cost) //Constructor with args that set up the data that passed in by the derived classes' constructor.
{
	loc1 = new char [strlen(L1) + 1];
	strcpy (loc1,L1);

	loc2 = new char [strlen(L2) + 1];
	strcpy (loc2,L2);

	transport_id = id;
	transport_cost = cost;
	type = identifier;
	rent_hours = hours;
	repair = repair_stat;

}

transport::transport(const transport & to_copy) //Copy the data into the nodes.
{
	loc1 = new char [strlen(to_copy.loc1) + 1];
	strcpy (loc1,to_copy.loc1);
	
	loc2 = new char [strlen(to_copy.loc2) + 1];
	strcpy (loc2,to_copy.loc2);

	transport_id = to_copy.transport_id;
	transport_cost = to_copy.transport_cost;
	type = to_copy.type;
	rent_hours = to_copy.rent_hours;
	repair = to_copy.repair;

}
transport::~transport() 
{
	if (loc1)
		delete [] loc1;
	if (loc2)
		delete [] loc2;
}
/***************************************************************/

scooter::scooter():battLevel(0)
{
}
//Constructor with argument that will pass whatever the input data from the user back to the base class constructor.
scooter::scooter(bool repair_stat, float hours, int identifier, int batteryLvl, char * scootLoc1, char * scootLoc2, int id, int cost): transport(repair_stat,hours,identifier,scootLoc1,scootLoc2,id,cost)
{
	battLevel = batteryLvl;
}
scooter::scooter (const scooter & to_copy):transport(to_copy)
{
	//only do this for scooter specific dynamic data:
	battLevel = to_copy.battLevel;
	
}

scooter::~scooter()
{
}

/*****************************************************************/
zipCar::zipCar():gasCheck(0),plate(NULL),fill(false)
{
}

zipCar::zipCar(bool repair_stat, float hours, int identifier, char * license, int gas, char * zipLoc1, char * zipLoc2, int id, int cost): transport(repair_stat,hours,identifier,zipLoc1,zipLoc2,id,cost) //This is the constructor with argument to pass into the base class
{
	fill = fillUp(); //Function call
	gasCheck = gas;
	plate = new char [strlen(license) + 1];
	strcpy (plate,license);

}

zipCar::zipCar(const zipCar & to_copy): transport(to_copy)
{
	fill = to_copy.fill;
	gasCheck = to_copy.gasCheck;
	plate = new char [strlen(to_copy.plate) + 1];
	strcpy (plate,to_copy.plate);
}

zipCar::~zipCar()
{
	if (plate)
		delete []  plate;
}

bool zipCar::fillUp() //The function to read in the value to check if the car is filled up with gas
{
	char response;
	cout << "Did you fill up the gas tank? Type Y if you did, N if you did not: ";
	cin >> response;
	cin.ignore (100,'\n');
	response = toupper(response);
	if (response == 'Y')
		return true;
	else 
		return false;
}

/********************************************************************/
bicycle::bicycle():tires(false)
{
}
//The constructor with args to pass data to the base class construct.
bicycle::bicycle (bool repair_stat, float hours, int identifier, char * bikeLoc1, char * bikeLoc2, int id, int cost): transport(repair_stat,hours,identifier,bikeLoc1,bikeLoc2,id,cost)
{
	tires = tire_check();
}
//Copy constructor.
bicycle::bicycle (const bicycle & to_copy): transport(to_copy)
{
	tires = to_copy.tires;
}

bicycle::~bicycle()
{

}

bool bicycle::tire_check()
{
	char response;
	cout << "Are the tires flat? Type Y if they are, N if they are not: ";
	cin >> response;
	cin.ignore(100,'\n');
	response = toupper(response);
	if (response == 'Y')
		return true;
	else
		return false;
}
/******************************************************************/
//Getters
int transport::getID()
{
	return transport_id;
}
int transport::getCost()
{
	return transport_cost;
}
int transport::getType()
{
	return type;
}
/*******************************************************************/
//Separates display function for each derived class.
void bicycle::display_all()
{
	cout << endl;
	cout << "The bicycle is at the corner of " << loc1 << " and " << loc2 << "." << endl;
	cout << "Its ID: " << transport_id << endl;	
	if (repair)
		cout << "The bike needs a tune up!" << endl;
	else
		cout << "The bike is fine." << endl;
	if (tires)
		cout << "The tires are flat!" << endl;
	else
		cout << "The tires are not flat." << endl;
	cout << "The cost to use it: " << transport_cost << endl ;
	cout << "The total time rented is: " << rent_hours << endl << endl;
}

void zipCar::display_all()
{
	cout << endl;
	cout << "The zip car is at the corner of " << loc1 << " and " << loc2 << "." << endl;
	cout << "Its license plate is: " << plate << endl;
	if (gasCheck)
		cout << "The car needs a gas refill." << endl;
	else
		cout << "The car does not need a gas refill." << endl;
	if (fill)
		cout << "The user has filled up the gas tank before." << endl;
	else
		cout << "The user has never filled up the gas tank before. " << endl;
	if (repair)
		cout << "The car needs a tune up!" << endl;
	else
		cout << "The car is fine." << endl;
	cout << "Its ID: " << transport_id << endl;
	cout << "The cost to use it: " << transport_cost << endl;
	cout << "The total time rented is: " << rent_hours << endl << endl;	
}
void scooter::display_all()
{
	cout << endl;
	cout << "The scooter is at the corner of " << loc1 << " and " << loc2 << "." << endl;
	cout << "The battery level is:" << battLevel << endl;
	if (repair)
		cout << "The scooter needs a tune up!" << endl;
	else
		cout << "The scooter is fine." << endl;
	cout << "Its ID: " << transport_id << endl;
	cout << "The cost to use it: " << transport_cost << endl;
	cout << "The total time rented is: " << rent_hours << endl << endl;
}
