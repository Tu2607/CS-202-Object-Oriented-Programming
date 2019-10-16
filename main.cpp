//Tu Vu CS202
//Program 2
//October 23,2018
//Purpose of this program: This program's purpose is to help a rental transportation company manages all of their vehicles.  With using a doubly linked list, it's easier to
//manage the fleet of vehicle since the company can just pick out any vehicle from the fleet to display and remove it!  Have fun using this program. 

#include "general.h"

using namespace std;

int main() 
{
	company rentService;	
	char user_response;

	char location1 [100];
	char location2 [100];
	int t_id = 0;
	int t_cost = 0;
	int flag = 0;
	int v_id = 0;
	int vehicle_identifier = 0;
	float hours = 0;
	bool repair_stat;

	cout << "Hello and welcome to the management program for Portland's transportation vehicle. We need your help on reporting the current location, id and cost of the unit." << endl << endl;
	
	cout << "Are you ready to enter the information? Type Y to begin: ";
	cin >> user_response;
	cin.ignore(100,'\n');
	user_response = toupper(user_response);
	
	if (user_response == 'Y')
	{
		do 
		{
			cout <<"The 1st street: ";
			cin.get(location1,100,'\n');
			cin.ignore(100,'\n');

			cout <<"The 2nd street: ";	
			cin.get(location2,100,'\n');
			cin.ignore(100,'\n');

			cout <<"The vehicle's id: ";
			cin >> t_id;
			cin.ignore (100,'\n');

			cout <<"The cost for rental: ";
			cin >> t_cost;
			cin.ignore (100,'\n');

			cout <<"The total hours the vehicle was rented: ";
			cin >> hours;
			cin.ignore (100,'\n');

			cout << "Does it need repair? Type Y if it does, N if it does not: ";
			cin >> user_response;
			cin.ignore (100,'\n');
			user_response = toupper(user_response);

			if (user_response = 'Y')
				repair_stat = true;
			else
				repair_stat = false;

			cout <<"The type of vehicle (Type 1 for scooter, 2 for zip car, 3 for bike): ";
			cin >> flag;
			cin.ignore (100,'\n');
			if (flag == 1)
			{
				int battery;
				cout << "Please enter the current battery level of the scooter: ";
				cin >> battery;
				cin.ignore (100,'\n');


				vehicle_identifier = 1;
				scooter * temp = new scooter(repair_stat,hours,vehicle_identifier,battery,location1,location2,t_id,t_cost); // A temp node with type scooter
				rentService.addVehicle(*temp);
				delete temp;
			}
			else if (flag == 2)
			{
				char license [100];
				cout << "Enter the license plate: ";
				cin.get(license,100,'\n');
				cin.ignore (100,'\n');
				
				int gas;
				cout << "If the car need to refill please type in '1', if not type '0': ";
				cin >> gas;
				cin.ignore (100,'\n');

				vehicle_identifier = 2;
				zipCar * temp = new zipCar(repair_stat,hours,vehicle_identifier, license, gas,location1,location2,t_id,t_cost); //A temp node with type zipCar
				rentService.addVehicle(*temp);
				delete temp;
			}
			else if (flag == 3)
			{
				vehicle_identifier = 3;
				bicycle * temp = new bicycle(repair_stat,hours,vehicle_identifier,location1,location2,t_id,t_cost); //A temp node with type bicycle
				rentService.addVehicle(*temp);
				delete temp;
			}

			cout <<"Is there another vehicle you need to add? If so, type Y: ";
			cin >> user_response;
			cin.ignore(100,'\n');
			user_response = toupper(user_response);
			
		}
		while (user_response == 'Y');
	}
	else 
	{
		cout << "Thank you for your time" << endl;
		return 0;
	}

	do 
	{
		cout << "Now as a employee of the company, you have several option on what to do with the vehicles:" << endl;
		cout << "Type 1 to display all the reported vehicles and their information." << endl;
		cout << "Type 2 to see the total profit that the company made." << endl;
		cout << "Type 3 to call back a specific vehicle that was reported." << endl;
		cout << "Type 4 to call all the vehicles back." << endl << endl;
		cout << "What do you want to do? Please enter a number from the list above: ";
		cin >> flag;
		cin.ignore(100,'\n');

		if (flag == 1)
			rentService.display_vehicle();
		else if (flag == 2)
			rentService.company_income();
		else if (flag == 3)
		{
			cout <<"Please enter the id for the vehicle you want to remove: ";	
			cin >> v_id;
			cin.ignore (100,'\n');

			if (rentService.remove_specific(v_id))
				cout << "The car has been recalled." << endl << endl;
			else
				cout << "The car was not reported or we can't recall it." << endl << endl;
		}	
		else if (flag ==4)
		{
			if (rentService.remove_all())
				cout << "All the vehicles have been called back" << endl << endl;
			else
				cout << "There is no vehicles to call back." << endl << endl;
		}
		cout << "Do you want to select another option? Type Y or else type in N: ";
		cin >> user_response;
		cin.ignore(100,'\n');
		user_response = toupper(user_response);
		if (user_response != 'Y')
		{
			cout << "Thank you for your time." << endl;
			return 0;
		}
	}
	while (user_response == 'Y');
	
	return 0;
}











